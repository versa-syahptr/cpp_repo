#include <stdio.h>
#include <tchar.h>
#include <windows.h>
int _tmain(int argc, _TCHAR* argv[])
{
   if (argc != 2)
   {
      wprintf(L"Argument is required: Process ID to kill\n");
      return -1;
   }
   if (wcsspn(argv[1], L"01234567890") < wcslen(argv[1]))
   {
      wprintf(L"Process ID should be positive integer\n");
      return -1;
   }
   int pid = _wtoi(argv[1]);
   HANDLE handle = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
   if (handle == NULL)
   {
      wprintf(L"Cannot open process with ID %d, error code: %d\n", pid, GetLastError());
      return -1;
   }
   if (TerminateProcess(handle, -1))
   {
      wprintf(L"Process with ID %d has been terminated\n", pid, GetLastError());
   }
   else {
      wprintf(L"Termination of the process with ID %d failed, error code: %d\n", pid, GetLastError());
      return -1;
   }
   CloseHandle(handle);
   return 0;
}
