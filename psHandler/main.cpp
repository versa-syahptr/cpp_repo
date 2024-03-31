#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string.h>
#include<stdlib.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("tes");
char* filename;

void pkill(const char *pname)
{
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof (pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (strcmp(pEntry.szExeFile, pname) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                                          (DWORD) pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}

int main(int argc, _TCHAR* argv[])
{
    // args handling
    if (argc != 2)
    {
        printf("filename param is required");
        return -1;
    }
    filename = argv[1];
    WNDCLASS wc = {0};


    // Set up and register window class
    wc.lpfnWndProc = WindowProcedure;
    wc.lpszClassName = szClassName;
    RegisterClass(&wc);
    HWND hWin = CreateWindow(szClassName, _T(""), 0, 0, 0, 0, 0, NULL, NULL, NULL, 0);

    BOOL bRet;
    MSG msg;
    while( (bRet = GetMessage( &msg, hWin, 0, 0 )) != 0)
    {
        if (bRet == -1)
        {
            exit(-1);
            // handle the error and possibly exit
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return 0;
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_POWERBROADCAST:
            printf("WM_POWERBROADCAST\n");
            switch (wParam)
            {
                case PBT_APMPOWERSTATUSCHANGE:
                    printf("PBT_APMPOWERSTATUSCHANGE\n");
                    break;
                case PBT_APMRESUMEAUTOMATIC:
                    printf("PBT_APMRESUMEAUTOMATIC\n");
                    CreateProcess(filename, NULL, NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL);
                    //system(filename);
                    exit(0);
                    break;
                case PBT_APMSUSPEND:
                    printf("PBT_APMSUSPEND\n");
                    pkill(filename);
                    break;
            }
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
