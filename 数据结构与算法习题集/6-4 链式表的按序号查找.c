/*
 * @Author: lyilan
 * @Date: 2021-03-31 21:58:34
 * @Description: for my ying~
 */
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth(List L, int K);

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR)
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType FindKth(List L, int K)
{
    if (!L || K < 1)
        return ERROR;
    List p = L;
    int i = 1;
    while (i < K && p)
    {
        i++;
        p = p->Next;
    }
    if (!p)
        return ERROR;
    return p->Data;
}