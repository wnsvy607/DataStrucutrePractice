#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int data;

typedef struct BTree {
    data value;
    struct BTree *left;
    struct BTree *right;
} btree;

btree *CreateBtree() {
    btree *root = (btree *) malloc(sizeof(btree));
    root->value = NULL;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int isEmpty(btree *bt) {
    if (bt->value == NULL)
        return TRUE;
    else
        return FALSE;
}


void SetLeftSubTree(btree *parent, btree *LChild) {
    //자식이 이미 있으면 메모리 해제, 메모리 누수 가능성 존재
    if (parent->left != NULL)
        free(parent->left);
    parent->left = LChild;
}

void SetRightSubTree(btree *parent, btree *RChild) {
    //자식이 이미 있으면 메모리 해제, 메모리 누수 가능성 존재
    if (parent->right != NULL)
        free(parent->right);
    parent->right = RChild;
}

btree *GetLChild(btree *bt) {
    return bt->left;
}

btree *GetRChild(btree *bt) {
    return bt->right;
}

data GetData(btree *bt) {
    return bt->value;
}

void SetData(btree *bt, data item) {
    bt->value = item;
}

//중위 순회
void inOrderPrint(btree* bt){
    if(bt == NULL)
        return;

    inOrderPrint(GetLChild(bt));
    printf("%d ", GetData(bt));
    inOrderPrint(GetRChild(bt));

}

//전위 순회
void preOrderPrint(btree* bt){
    if(bt == NULL)
        return;
    printf("%d ", GetData(bt));
    preOrderPrint(GetLChild(bt));
    preOrderPrint(GetRChild(bt));
}

//후위 순회
void postOrderPrint(btree* bt){
    if(bt == NULL)
        return;

    postOrderPrint(GetLChild(bt));
    postOrderPrint(GetRChild(bt));
    printf("%d ", GetData(bt));
}

int main() {
    btree* bt1 = CreateBtree();
    btree* bt2 = CreateBtree();
    btree* bt3 = CreateBtree();
    btree* bt4 = CreateBtree();
    btree* bt5 = CreateBtree();
    btree* bt6 = CreateBtree();
    btree* bt7 = CreateBtree();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);
    SetData(bt7, 7);

    SetLeftSubTree(bt1, bt2);
    SetRightSubTree(bt1, bt3);
    SetLeftSubTree(bt2, bt4);
    SetRightSubTree(bt2, bt5);
    SetLeftSubTree(bt3, bt6);
    SetRightSubTree(bt3, bt7);


    inOrderPrint(bt1); //중위 순회
    printf("\n");
    preOrderPrint(bt1); //전위 순회
    printf("\n");
    postOrderPrint(bt1); //후위 순회
}
