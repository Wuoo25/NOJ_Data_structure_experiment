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

BTNode* PreCreateBT(BTNode* t)
{
    char ch;
    do
    {
        scanf_s("%c", &ch);
    } while (ch == ' ');
    if (ch == '#')
        t = NULL;
    else
    {
        t = (BTNode*)malloc(sizeof(BTNode));
        t->element = ch;
        t->lChild = PreCreateBT(t->lChild);
        t->rChild = PreCreateBT(t->rChild);
    }
    return t;
}

void PreMakeTree(BinaryTree* bt)
{
    bt->root = PreCreateBT(bt->root);
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

int TreeHeight(BinaryTree* bt)/*计算高度*/
{
    Height(bt->root);
}

int Height(BTNode* t)
{
    int lHeight, rHeight;
    if (t == NULL)
        return 0;
    else
    {
        lHeight = Height(t->lChild) + 1;
        rHeight = Height(t->rChild) + 1;
    }
    return (lHeight > rHeight ? lHeight : rHeight);
}

int TreeSize(BinaryTree* bt)/*结点个数*/
{
    return Size(bt->root);
}

int Size(BTNode* t)
{
    if (!t)
        return 0;
    else
        return Size(t->lChild) + Size(t->rChild) + 1;
}

int CountTreeLeaf(BinaryTree* bt)/*叶子结点个数*/
{
    return CountLeaf(bt->root);
}

int CountLeaf(BTNode* t)
{
    if (!t)
        return 0 ;
    else
    {
        if ((t->lChild) == NULL && (t->rChild) == NULL)
        {
            return 1;
        }
        else
            return CountLeaf(t->lChild) + CountLeaf(t->rChild);
    }
}

int CountTreeNode(BinaryTree* bt)/*度为1结点个数*/
{
    return CountNode(bt->root);
}

int CountNode(BTNode* t)
{
    if (!t)
        return 0;
    if ((t->lChild) == NULL && (t->rChild) != NULL)
    {
        return CountNode(t->rChild) + 1;
    }
    else
    {
        if ((t->lChild) != NULL && (t->rChild) == NULL)
        {
            return CountNode(t->lChild) + 1;
        }
        return CountNode(t->lChild) + CountNode(t->rChild);
    }
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

int main()
{

    BinaryTree t;

    PreMakeTree(&t);
    
    printf("PreOrder: "); PreOrderTree(&t); printf("\n");
    printf("InOrder: "); InOrderTree(&t); printf("\n");
    printf("PostOrder: "); PostOrderTree(&t); printf("\n");

    printf("%d\n", TreeHeight(&t));
    printf("%d ", TreeSize(&t));
    printf("%d ", CountTreeLeaf(&t));
    printf("%d\n", CountTreeNode(&t));
    
    TreeClear(&t);
    printf("\n");
    return 0;

}