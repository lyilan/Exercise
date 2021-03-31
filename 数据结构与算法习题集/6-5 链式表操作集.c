/*
 * @Author: lyilan
 * @Date: 2021-03-31 22:06:05
 * @Description: for my ying~
 */
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR)
            printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
        {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR)
        printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR)
        printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR)
        printf("Wrong Answer\n");
    for (P = L; P; P = P->Next)
        printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */

Position Find(List L, ElementType X)
{
    if (!L)
        return ERROR;
    Position p = L;
    while (p && p->Data != X)
        p = p->Next;
    if (!p)
        return ERROR;
    return p;
}

List Insert(List L, ElementType X, Position P)
{
    if (!L || P == L)
    {
        List s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = L;
        return s;
    }
    Position p = L;
    while (p && p->Next != P)
    {
        p = p->Next;
    }
    if (!p)
    {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
    else
    {
        List s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = P;
        p->Next = s;
    }
    return L;
}

List Delete(List L, Position P)
{
    if (L == NULL || P == NULL)
    {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    if (L == P)
    {
        L = L->Next;
        free(P);
        return L;
    }
    Position p = L;
    while (p && p->Next != P)
    {
        p = p->Next;
    }
    if (p == NULL)
    {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    p->Next = P->Next;
    free(P);
    return L;
}