#include "DLinkList.h"
#include <stdio.h>
#include <stdlib.h>
DLinkList InitDLinkList() {
    DLinkList L = (DNode *)malloc(sizeof(DNode));
    if (!L) {
        return NULL;
    }
    L->next = NULL;  //空表头结点next指向NULL
    L->prior = NULL; //头结点prior指向NULL
    return L;
}

LinkList InitLinkList() {
    LinkList L = (LNode *)malloc(sizeof(LNode));
    if (!L) {
        return NULL;
    }
    L->next = L; //循环单链表头结点初始化时指向头结点
    return L;
}

Bool IsEmpty(DLinkList L) {
    if (L->next)
        return False;
    return True;
}

Bool IsEmptyLinkList(LinkList L) {
    if (L->next == L) {
        return True; //指向自身时为空
    }
    return False;
}

Bool IsTail(LinkList L, LNode *p) {
    if (!p || !L) {
        return False;
    }
    if (p->next == L) {
        return True;
    }
    return False;
}

Bool InsertNextNode(DNode *p, DNode *q) {
    if (!p || !q) {
        return False;
    }
    q->next = p->next;
    if (p->next != NULL) {
        p->next->prior = q;
    } //判断是否为最后一个结点，进行特殊操作
    q->prior = p;
    p->next = q;
    return True;
}

Bool DeleteNode(DNode *p) {
    if (!p) {
        return False;
    }
    DNode *q = p->next;
    if (!q) {
        return False;
    }
    p->next = q->next; // p->next指向q->next
    if (q->next) {     // q->next不为空
        q->next->prior = p;
    }
    free(q);
    return True;
}

void PrintList(DLinkList L) {
    if (!L) {
        return;
    }
    DNode *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
