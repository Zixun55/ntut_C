#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 100

typedef struct binaryTree_s{
    char data;
    struct binaryTree_s *left, *right;
} binaryTree_t;

binaryTree_t *buildBinaryTree(char *inOrder, char *pOrder, int start, int end, int *pIndex, int isPreOrder);
void print(binaryTree_t *root);

int main(){
    binaryTree_t *root;
    char code, inOrder[SIZE], pOrder[SIZE];
    int isPreOrder = 0, pIndex;

    for (int i = 0; i < 2; i++){
        scanf("%c%*c", &code);
        if (code == 'P')
            isPreOrder = 1;//是前序或後序
        if (code == 'I')
            scanf("%s%*c", inOrder);
        else
            scanf("%s%*c", pOrder);
    }
    

    pIndex = isPreOrder ? 0 : strlen(inOrder) - 1;
    root = buildBinaryTree(inOrder, pOrder, 0, strlen(inOrder) - 1, &pIndex, isPreOrder);
    print(root);

    return 0;
}

binaryTree_t *createNewNode(char data){
    binaryTree_t *newNode = (binaryTree_t *)malloc(sizeof(binaryTree_t));

    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

int search(char *inOrder, int start, int end, char ch){
    for (int i = start; i <= end; i++)
        if (inOrder[i] == ch)
            return i;
    return -1;
}

binaryTree_t *buildBinaryTree(char *inOrder, char *pOrder, int start, int end, int *pIndex, int isPreOrder){
    if (start > end)
        return NULL;

    char data = isPreOrder ? pOrder[(*pIndex)++] : pOrder[(*pIndex)--];
    binaryTree_t *newNode = createNewNode(data);
    int inIndex = search(inOrder, start, end, data);

    if (isPreOrder){
        newNode->left = buildBinaryTree(inOrder, pOrder, start, inIndex - 1, pIndex, isPreOrder);
        newNode->right = buildBinaryTree(inOrder, pOrder, inIndex + 1, end, pIndex, isPreOrder);
    }
    else{
        newNode->right = buildBinaryTree(inOrder, pOrder, inIndex + 1, end, pIndex, isPreOrder);
        newNode->left = buildBinaryTree(inOrder, pOrder, start, inIndex - 1, pIndex, isPreOrder);
    }

    return newNode;
}

void print(binaryTree_t *root){
    binaryTree_t **binaryTreeArray = (binaryTree_t **)malloc(SIZE * sizeof(binaryTree_t *));
    int length = 0, index = 0;

    binaryTreeArray[length++] = root;
    while (index < length){
        printf("%c", binaryTreeArray[index]->data);
        if (binaryTreeArray[index]->left != NULL)
            binaryTreeArray[length++] = binaryTreeArray[index]->left;
        if (binaryTreeArray[index]->right != NULL)
            binaryTreeArray[length++] = binaryTreeArray[index]->right;
        index++;
    }
    free(binaryTreeArray);
}

// 給定前序或後序以及中序，產生唯一個Binary Tree，依序印出Tree的內容，印出順序，由上而下，由左而右印出。

// 前序代碼：P
// 中序代碼：I
// 後序代碼：O

// --------------
// 輸入說明

// 第一筆輸入前序、中序或後序代碼。
// 第二筆輸入上一筆輸入種類尋訪的結果，大寫英文字母。
// 第三筆輸入前序、中序或後序代碼。
// 第四筆輸入上一筆輸入種類尋訪的結果，大寫英文字母。

// -------------
// 輸出說明

// 輸出為一二元樹的內容，由上而下，由左而右。

// 範例一
// -------------
// Input:
// P
// ABCDEFGHI
// I
// BCAEDGHFI

// --------------
// Output :
// ABDCEFGIH


// 範例二:
// -------------
// Input:
// O
// CBEHGIFDA
// I
// BCAEDGHFI

// --------------
// Output:
// ABDCEFGIH