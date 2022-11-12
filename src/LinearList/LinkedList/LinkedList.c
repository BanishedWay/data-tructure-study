#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkList InitLinkList() {
    LinkList L = (LinkList)malloc(sizeof(LNode)); //创建头结点
    if (!L) {
        return NULL;
    }
    L->next = NULL;
    return L;
}

void PrintList(LinkList L) {
    if (IsEmpty(L)) {
        return;
    }
    LNode *p = L;
    while (p->next) {
        printf("%d ", p->next->data);
        p = p->next; //循环遍历链表，直到指针指向NULL
    }
    printf("\nPrint finished\n");
}

Bool IsEmpty(LinkList L) {
    return (L->next == NULL); //判断是否为空表
}

int Length(LinkList L) {
    LNode *p = L->next;
    int length = 0;
    while (p) { //从第一个结点开始，判断第一个结点是否为空
        length++;
        p = p->next; //判断一个结点不为空，长度+1
    }
    return length;
}
LNode *GetElem(LinkList L, int i) {
    if (i < 0) {
        return NULL;
    }
    LNode *p = L; // p指向头结点
    int j = 0;    //开始计数，从0开始，j=k时，p指向第k个结点
    while (p && j < i) {
        p = p->next;
        j++;
    } //跳出循环时，j==i，此时指向第i个结点
    return p;
}

LNode *LocateElem(LinkList L, ElemType x) {
    LNode *p = L->next; // p指向第一个结点，因为头结点数据域为空
    while (p && p->data != x) {
        p = p->next; //当链表遍历结束或者找到目标结点时退出循环
    }
    return p; //没有x或者为空时，p==NULL
}

Bool ListInsert(LinkList L, int i, ElemType x) {
    if (i < 1) {
        return False;
    }                             // i值不合法
    LNode *p = GetElem(L, i - 1); //获取第i个结点的前驱，结点不存在时为空
    return InsertNextNode(p, x);
}

Bool InsertNextNode(LNode *p, ElemType x) {
    if (!p) {
        return False;
    } //当传入结点为空
    LNode *q = (LNode *)malloc(sizeof(LNode));
    if (!q) {
        return False;
    } //地址分配失败
    q->data = x;
    q->next = p->next;
    p->next = q;
    return True;
}

Bool InsertPrevNode(LNode *p, ElemType x) {
    if (!p) {
        return False;
    }                                          //结点为空
    LNode *q = (LNode *)malloc(sizeof(LNode)); //分配内存空间
    if (!q) {
        return False;
    } //分配失败
    q->data = p->data;
    q->next = p->next;
    p->next = q;
    p->data = x;
    //将结点插入在p结点的后方，然后交换p结点和新的结点的数据
    return True;
}

Bool ListDelete(LinkList L, int i, ElemType *e) {
    if (i < 1) {
        return False;
    } //位序不合法
    LNode *p = GetElem(L, i - 1);
    if (!p) {
        return False;
    }                   //判断是否存在第i-1个结点
    LNode *q = p->next; // q指向需要删除的结点
    if (!q) {
        return False;
    }                  //不存在第i个结点
    p->next = q->next; //将链表从中间断开
    *e = q->data;      //返回第i个结点的数据域
    free(q);
    return True;
}

Bool DeleteNode(LNode *p) {
    if (!p) {
        return False;
    }
    LNode *q = p->next;
    if (!q) {
        return False;
    } //当q不是最后一个结点时，不能使用这种方法
    p->data = q->data;
    p->next =
        q->next; //交换被删除结点和后继结点的数据域，然后删除后继结点，达到删除目的结点的效果
    free(q);
    return True;
}

LinkList ListTailInsert(ElemType *arr, int length) {
    LinkList L = InitLinkList();
    if (length < 1) {
        return L;
    }                      //长度为<1时返回NULL
    LNode *cur, *tail = L; //建立表尾指针指向表尾
    for (int i = 0; i < length; i++) {
        cur = (LNode *)malloc(sizeof(LNode));
        if (!cur) {
            return False;
        }                   //内存分配失败
        cur->data = arr[i]; //赋值给新的结点
        tail->next = cur;   //将新的结点插入到表尾
        tail = cur;         // tail指向表尾
    }
    tail->next = NULL;
    return L;
}

LinkList ListHeadInsert(ElemType *arr, int length) {
    LinkList L = InitLinkList();
    if (L == NULL) {
        printf("NULL\n");
    }

    if (length < 1) {
        return L;
    }
    LNode *cur = L;
    printf("The array is: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%d ", arr[length - i - 1]);
        InsertNextNode(cur, arr[i]); //在头结点后插入新的结点
    }
    printf("\nFinish inserting\n");
    return L;
}

int GetLength(LinkList L) {
    int length = 0;
    LNode *p = L->next;
    while (p) {
        length++;
    }
    return length;
}

Bool equal(LinkList L1, LinkList L2) {
    if (L1->data == L2->data) {
        return True;
    }
    return False;
}
