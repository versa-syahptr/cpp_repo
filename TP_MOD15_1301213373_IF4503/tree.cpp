#include "tree.h"

/*
    Nama : Versa Syahputra Santo
    NIM  : 13012133733
    Kelas: IF-45-03
    File : tree.cpp
*/

adrNode newNode_1301213373(infotype x){
    adrNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode_1301213373(adrNode &root, adrNode p){
    if (root == NULL){
        root = p;
    } else {
        if (root->info >= p->info){
            insertNode_1301213373(root->left, p);
        } else {
            insertNode_1301213373(root->right, p);
        }
    }
}

void printPreOrder_1301213373(adrNode root){
    if (root != NULL){
        cout << root->info << " ";
        printPreOrder_1301213373(root->left);
        printPreOrder_1301213373(root->right);
    }
}

adrNode findNode_1301213373(adrNode root, infotype x){
    if (root != NULL){
        if (root->info == x){
            return root;
        } else if (root->info < x){
            return findNode_1301213373(root->left, x);
        } else {
            return findNode_1301213373(root->right, x);
        }
    } else {
        return NULL;
    }
}

void printDescendant_1301213373(adrNode root, infotype x){
    adrNode p = findNode_1301213373(root, x);
    if (p != NULL){
        printPreOrder_1301213373(p);
    } else {
        cout << x << " tidak ditemukan\n";
    }
}

int sumNode_1301213373(adrNode root){
    if (root != NULL){
        return root->info + sumNode_1301213373(root->left) + sumNode_1301213373(root->right);
    } else {
        return 0;
    }
}

int countLeaves_1301213373(adrNode root){
    if (root == NULL){
        return 0;
    }
    if (root->left == NULL && root->right == NULL){
        return 1;
    }
    return countLeaves_1301213373(root->left) + countLeaves_1301213373(root->right);
}

int heightTree_1301213373(adrNode root){
    if (root != NULL){
        int lh, rh;
        lh = heightTree_1301213373(root->left);
        rh = heightTree_1301213373(root->right);
        if (lh > rh){
            return lh + 1;
        } else {
            return rh + 1;
        }
    } else {
        return 0;
    }
}
