#include "LinearList.h"
#include <stdio.h>
#include <stdlib.h>

int InitList(SqList *L) {
    for (int i = 0; i < MAXSIZE; i++) {
        L->data[i] = 0;
    }
    L->length = 0;
    return OK;
}

int InitDynamicList(SeqList *L) {
    L->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    L->length = 0;
    L->maxSize = MAXSIZE;
    return OK;
}

int IncreaseDynamicList(SeqList *L, int len) {
    ElemType *p = L->data;
    L->data =
        (ElemType *)malloc((L->maxSize + len) * sizeof(ElemType)); //重新分配空间
    for (int i = 0; i < L->length; i++) {
        L->data[i] = p[i]; //将原本的数据元素复制到新的内存空间中
    }
    L->maxSize += len;
    free(p); //释放原先的内存空间
    return OK;
}

int ListInsert(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return ERROR; //判断输入的参数是否有效
    }
    if (L->length >= MAXSIZE) {
        return ERROR; //数组已满
        /*
         * IncreaseDynamicList(L,5);
         * 动态数组时可以添加长度
         * */
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e; //插入元素
    L->length++;        //长度+1
    return OK;
}

int ListDelete(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) {
        return ERROR; //判断输入有效
    }
    *e = L->data[i - 1];
    for (int j = i - 1; j < L->length - 1; j++) {
        L->data[j] = L->data[j + 1]; //元素后移
    }
    L->length--; //长度-1
    return 1;
}

ElemType GetElem(SqList L, int i) {
    return L.data[i - 1];
}

int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1; //返回位序
        }
    }
    return -1; //查找失败返回-1
}

int printList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("线性表长度：%d\n", L.length);
    return OK;
}

int InitListArray(SqList *L, ElemType *arr) {
    for (int i = 0; arr[i] != -1; i++) {
        L->data[i] = *(arr + i);
        L->length++;
    }
    return OK;
}
