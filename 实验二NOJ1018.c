#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;
typedef char ElemType;

typedef struct btnode
{
    ElemType element;
    struct btnode* lChild;
    struct btnode* rChild;
}BTNode;

typedef struct binarytree
{
    BTNode* root;
}BinaryTree;

void Create(BinaryTree* bt)
{
    bt->root = NULL;
}

BTNode* NewNode(ElemType x, BTNode* ln, BTNode* rn)
{
    BTNode* p = (BTNode*)malloc(sizeof(BTNode));
    p->element = x;
    p->lChild = ln;
    p->rChild = rn;
    return p;
}

BOOL Root(BinaryTree* bt, ElemType* x)
{
    if (bt->root)
    {
        x = &bt->root->element;
        return TRUE;
    }
    else
        return FALSE;
}

void MakeTree(BinaryTree* bt, ElemType e, BinaryTree* left, BinaryTree* right)
{
    if (bt->root || left == right)
        return;

    bt->root = NewNode(e, left->root, right->root);
    left->root = right->root = NULL;
}

void PreOrder(BTNode* t)
{
    if (!t)
        return;

    printf("%c ", t->element);  //访问根节点
    PreOrder(t->lChild);
    PreOrder(t->rChild);
}

void PreOrderTree(BinaryTree* bt)
{
    PreOrder(bt->root);
}

void InOrder(BTNode* t)
{
    if (!t)
        return;

    InOrder(t->lChild);
    printf("%c ", t->element);
    InOrder(t->rChild);
}

void InOrderTree(BinaryTree* bt)
{
    InOrder(bt->root);
}

void PostOrder(BTNode* t)
{
    if (!t)
        return;

    PostOrder(t->lChild);
    PostOrder(t->rChild);
    printf("%c ", t->element);
}

void PostOrderTree(BinaryTree* bt)
{
    PostOrder(bt->root);
}

void Clear(BTNode* t)
{
    if (!t)
        return;

    Clear(t->lChild);
    Clear(t->rChild);
    free(t);
}

void TreeClear(BinaryTree* bt)
{
    Clear(bt->root);
}

int main(void)
{
    BinaryTree a, b, x, y, z, q;

    Create(&a); Create(&b); Create(&x); Create(&y); Create(&z); Create(&q);

    MakeTree(&x, 'K', &a, &b);
    MakeTree(&y, 'C', &x, &b);

    MakeTree(&z, 'G', &a, &y);

    MakeTree(&y, 'J', &a, &b);
    MakeTree(&x, 'F', &y, &z);

    MakeTree(&y, 'H', &a, &b);
    MakeTree(&z, 'E', &y, &x);

    MakeTree(&x, 'B', &a, &b);
    MakeTree(&y, 'A', &a, &x);

    MakeTree(&q, 'D', &z, &y);

    printf("PreOrder: "); PreOrderTree(&q); printf("\n");
    printf("InOrder: "); InOrderTree(&q); printf("\n");
    printf("PostOrder: "); PostOrderTree(&q); printf("\n");

    TreeClear(&q);

    printf("\n");

    return 0;
}