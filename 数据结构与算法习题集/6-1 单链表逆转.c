/*
 * @Author: lyilan
 * @Date: 2021-03-31 18:26:35
 * @Description: for my ying~
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Reverse(List L);

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

//迭代反转链表
List Reverse1(List L)
{
    if (L == NULL || L->Next == NULL)
        return L;
    List beg, mid, end;
    beg = NULL;
    mid = L;
    end = L->Next;
    while (end)
    {
        mid->Next = beg;
        beg = mid;
        mid = end;
        end = end->Next;
    }
    mid->Next = beg;
    return mid;
}

//递归翻转链表
List Reverse2(List L)
{
    if (L == NULL || L->Next == NULL)
        return L;
    else
    {
        List New_Head = Reverse(L->Next);
        L->Next->Next = L;
        L->Next = NULL;
        return New_Head;
    }
}

//头插法翻转链表
List Reverse(List L)
{
    List p = NULL, q;
    while (L)
    {
        q = L;
        L = L->Next;
        q->Next = p;
        p = q;
    }
    return p;
}

//