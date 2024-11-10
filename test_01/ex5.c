#include <stdio.h>
#include <stdlib.h>
int isPrime(int n)
{
    if(n == 2 || n == 3)
    {
        return 1;
    }
    else if(n % 2 == 0 || n % 3 == 0)
    {
        return 0;
    }
    else
    {
        for(int i = 5;i * i <= n;i++)
        {
            if(n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}
typedef struct Tree
{
    int data;
    struct Tree * lchild;
    struct Tree * rchild; 
}Tree;
typedef Tree * BiT;

void createTree(BiT * tree,int n)
{
    *tree = (BiT)malloc(sizeof(Tree));
    (*tree)->data = n;
    (*tree)->lchild = NULL;
    (*tree)->rchild = NULL;
    if(isPrime(n))
    {
        return;
    }
    for(int i = 2;i * i <= n;i++)
    {
        if(isPrime(i) && n % i == 0)
        {
            createTree(&(*tree)->lchild,i);
            createTree(&(*tree)->rchild,n / i);
            break;
        }
    }
}

void func(BiT  tree,int * num)
{
    if(tree == NULL)
    {
        return;
    }
    if(isPrime(tree->data))
    {
        (*num)++;
    }
    else
    {
        func(tree->lchild,num);
        func(tree->rchild,num);
    }
}
void freeTree(BiT tree)
{
    if(tree == NULL)
    {
        return;
    }
    freeTree(tree->lchild);
    freeTree(tree->rchild);
    free(tree);
}
int main(void)
{
    
    int a;
    scanf("%d",&a);
    int b = 0;
    for(int i = 2;i <= a;i++)
    {
        BiT tree = NULL;
        int * count = &b;
        createTree(&tree, i);
        func(tree, count);
        freeTree(tree);
    }
    printf("%d",b);
    return 0;
}
