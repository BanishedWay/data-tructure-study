#include "Application.h"
#include <stdio.h>
#include <stdlib.h>

Bool Question1(LinkList L, ElemType x) {
    LNode *p;
    if (!L) {
        printf("LinkList is Empty!\n");
        return False;
    }
    if (L->data != x) { //不等于x，进行递归调用
        Question1(L->next, x);
    } else {
        p = L;
        L = L->next;
        free(p);         //删除L，并指向下一结点
        Question1(L, x); //递归调用
    }
    return True;
}

Bool Question2(LinkList L, ElemType x) {
    if (!L->next) {
        printf("Empty LinkList\n");
        return False;
    }
    //设置前驱指针
    LNode *prev = L, *cur = L->next, *q;
    while (cur) {
        if (cur->data == x) { //相等时，修改前驱结点的指针，游标后移
            prev->next = cur->next;
            q = cur;
            cur = cur->next;
            free(q);
        } else {
            prev = cur;
            cur = cur->next;
        } //不等时，同步后移
    }
    return True;
}

Bool Question2_2(LinkList L, ElemType x) {
    if (!L->next) {
        printf("Empty List\n");
        return False;
    }
    LNode *p = L->next, *q = L;
    while (p) {
        if (p->data != x) {
            q->next = p;
            q = q->next;
        } //当不等于x时,插入到新的链表后面
        p = p->next;
    }
    q->next = NULL;
    return True;
}

Bool Question3(LinkList L) {
    if (!L->next) {
        return False;
    }
    LNode *p = L->next, *q = L, *cur;
    q->next = NULL;
    //采用头插法原地逆置
    while (p) {
        cur = q->next; //暂存下一个结点
        q->next = p;   //将结点插入到头结点后
        p = p->next;
        q->next->next = cur; //将暂存的链表放到第一个结点后
    }
    PrintList(L);
    return True;
}

void TestQuestion2() {
    int arr[10] = {1, 2, 3, 1, 1, 3, 2};
    LinkList L = ListHeadInsert(arr, 7);
    PrintList(L);

    Question2_2(L, 1);
    PrintList(L);
    return;
}

void TestQuestion3() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList L = ListHeadInsert(arr, 9);
    PrintList(L);

    Question3(L);
    return;
}

Bool Question4(LinkList L) {
    if (!L->next) {
        printf("Empty List\n");
        return False;
    }
    //定义辅助指针分别指向最小的结点和其前驱结点
    LNode *miniprev = L, *minip = L->next, *p = L->next, *prev = L;
    while (p) {
        if (p->data < minip->data) {
            minip = p;
            miniprev = prev;
        } //当当前结点的值小于minip指向的结点时,更新minip
        prev = p;
        p = p->next; //同步后移
    }
    //删除最小结点
    miniprev->next = minip->next;
    free(minip);
    return True;
}

void TestQuestion4() {
    int arr[10] = {1, 2, 3, 4, 0, 6, 7, 8, 9};
    LinkList L = ListHeadInsert(arr, 9);
    PrintList(L);

    Question4(L);
    PrintList(L);
    return;
}

Bool Question5(LinkList L) {
    if (!L->next) {
        return False;
    }
    LNode *p = L->next, *q = L, *cur;
    q->next = NULL;
    //采用头插法原地逆置
    while (p) {
        cur = q->next; //暂存下一个结点
        q->next = p;   //将结点插入到头结点后
        p = p->next;
        q->next->next = cur; //将暂存的链表放到第一个结点后
    }
    return True;
}

Bool Question5_2(LinkList L) {
    if (!L->next) {
        return False;
    }
    LNode *prev, *p = L->next, *q = p->next;
    p->next = NULL;
    while (q) {
        prev = p;
        p = q;
        q = q->next;
        p->next = prev;
    } //暂存三个相邻的结点,将中间的结点的指针指向前一个结点(游离的结点)
    L->next = p;
    return True;
}

void TestQuestion5() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkList L = ListHeadInsert(arr, 9);
    PrintList(L);

    Question5_2(L);
    PrintList(L);
    return;
}

Bool Question6(LinkList L) {
    if (!L) {
        return False;
    }
    LNode *p = L->next, *q = p->next, *prev;
    p->next = NULL; //只包含一个几点的单链表
    p = q;
    while (p) {
        q = p->next;
        prev = L;
        //循环遍历在L中找到比p小的前驱结点
        while (prev->next && prev->next->data < p->data) {
            prev = prev->next;
        } //循环结束条件为prev->next==NULL或prev->next->data>=p->data
        //两种情况都有prev->data<p->data
        p->next = prev->next;
        prev->next = p;
        //将p插入到prev后
        p = q; //循环遍历原链表之后的结点
    }
    return True;
}

void TestQuestion6() {
    int arr[10] = {3, 1, 3, 2, 5, 1, 10, 8, 9};
    LinkList L = ListHeadInsert(arr, 9);
    PrintList(L);

    Question6(L);
    PrintList(L);
    return;
}

Bool Question7(LinkList L, ElemType s, ElemType t) {
    if (!L->next) {
        return False;
    }
    //循环遍历，找到处于s和t之间的结点
    LNode *cur = L->next, *prev = L, *p;
    while (cur) {
        //判断结点的值是否满足条件
        if (cur->data > s && cur->data < t) {
            prev->next = cur->next;
            p = cur;
            cur = cur->next;
            free(p);
        } //删除结点
        else {
            cur = cur->next;
            prev = prev->next;
        } //同步后移
    }
    return True;
}

void TestQuestion7() {
    int arr[10] = {3, 1, 3, 2, 5, 1, 10, 8, 9};
    LinkList L = ListHeadInsert(arr, 9);
    PrintList(L);

    Question7(L, 1, 5);
    PrintList(L);
}
LNode *Question8(LinkList L1, LinkList L2) {
    //共同结点，则尾结点必然相同，共同结点之后的结点完全相同
    int l1 = GetLength(L1), l2 = GetLength(L2);
    LinkList shorter, longer;
    int dis;
    if (l1 > l2) {
        shorter = L2->next;
        longer = L1->next;
        dis = l1 - l2;
    } else {
        shorter = L1->next;
        longer = L2->next;
        dis = l2 - l1;
    }
    while (dis--) {
        longer = longer->next;
    }
    while (longer) {
        if (equal(longer, shorter)) {
            return longer;
        } else {
            longer = longer->next;
            shorter = shorter->next;
        }
    }
    return NULL;
}

void Question9(LinkList L) {
    if (!L->next) {
        return;
    }

    LNode *cur = L->next, *left = cur->next, *prev = L;
    cur->next = NULL; //原链表中只包含一个结点
    cur = left;
    while (cur) {
        prev = L;         //每次都从头开始寻找
        left = cur->next; //暂存还没有排序的链表
        while (prev->next && prev->next->data < cur->data) {
            prev = prev->next;
        } //找到小于cur的最后一个结点
        cur->next = prev->next;
        prev->next = cur;
        //将cur插入到prev的后面
        cur = left; // cur指向没有排序的链表
    }

    LNode *p = NULL;
    while (L->next) {
        p = L->next;
        L->next = p->next;
        printf("%d ", p->data);
        free(p);
    } //输出并销毁结点
    return;
}

void TestQuestion9() {

    int arr[10] = {3, 1, 3, 2, 5, 1, 10, 8, 9};
    LinkList L = ListHeadInsert(arr, 9);
    PrintList(L);

    Question9(L);
}
