#include "Queue.h"
#include <cstdio>
#include <cstdlib>

void InitQueue(SqQueue &Q) {
    //初始化时都设置为0
    Q.rear = Q.front = 0;
}

bool Empty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    //判断是否为满
    if ((Q.rear + 1) % MAXSIZE == Q.front) {
        return false;
    }

    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAXSIZE; //进行取余操作，
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.front == Q.rear) {
        return false; //判空
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE; //队头指针后移一位
    return true;
}

bool GetHead(SqQueue Q, ElemType &x) {
    if (Q.front == Q.rear) {
        return false; //空队列
    }
    x = Q.data[Q.front];
    return true;
}

void InitLinkQueue(LinkQueue &Q) {
    Q.front = Q.rear = (QNode *)malloc(sizeof(QNode));
    Q.front->next = NULL;
}

bool EmptyLink(LinkQueue &Q) {
    return Q.front == Q.rear;
}

void EnLinkQueue(LinkQueue &Q, ElemType &x) {
    QNode *s = (QNode *)malloc(sizeof(QNode));
    if (!s) {
        return;
    }
    s->data = x;
    s->next = NULL;
    //不带头结点需要进行判断并修改front
    Q.rear->next = s; //结点插入到rear后
    Q.rear = s;       //修改表尾指针
}

void DeLink(LinkQueue &Q, ElemType &x) {
    if (EmptyLink(Q)) {
        return;
    }
    QNode *s = Q.front->next; //带头结点的情况下，front指向头结点
    x = s->data;
    Q.front->next = s->next; // front指向后一个结点
    if (Q.rear == s) {
        Q.rear = Q.front; //判断是否为最后一个结点，是则修改为队空状态
    }
    free(s);
}
