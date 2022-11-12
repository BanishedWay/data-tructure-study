#include "Application.h"
#include <stdio.h>

int question1(SqList *L) {
    if (L->length < 1) {
        printf("空表\n");
        return ERROR;
    }
    int index = GetMinElem(L); //获取最小元素下标
    int res;
    res = L->data[index];
    L->data[index] = L->data[L->length - 1]; //获取被删除的元素值
    printf("删除成功\n");
    printf("%d\n", index);
    return res;
}

int question2(SqList *L) {
    if (L->length < 1) {
        printf("空表\n");
        return ERROR;
    }
    //交换前n/2个元素
    for (int i = 0; i < L->length / 2; i++) {
        swap(&L->data[i], &L->data[L->length - i - 1]); //交换次序
    }
    return OK;
}

int question3(SqList *L, ElemType x) {
    if (L->length < 1) {
        return ERROR;
    }
    //使用k计算当前数据元素前面等于x的数目
    int k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == x) {
            k++; //当==x时，k+1
        } else {
            L->data[i - k] = L->data[i]; //将不等于x的元素向前移动k的单位
        }
    }
    L->length -= k; //线性表长度-k
    return OK;
}

int question4(SqList *L, ElemType s, ElemType t) {
    if (s >= t || L->length < 1) {
        printf("ERROR\n");
        return ERROR;
    }
    //用j,k记录在s和t之间的数据元素
    int j = 0, k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] > s) {
            j = i;
            break;
        }
    }
    for (int i = j; i < L->length; i++) {
        if (L->data[i] >= t) {
            k = i;
            break;
        }
    }

    for (int i = 0; i < L->length - k; i++) {
        L->data[j + i] = L->data[k + i];
    }
    L->length -= k - j;
    return OK;
}

int question5(SqList *L, ElemType s, ElemType t) {
    if (s >= t || L->length < 1) {
        printf("Error\n");
        return ERROR;
    }
    //用k记录不在s~t之间的数据元素
    int k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] < s || L->data[i] > t) {
            L->data[k] = L->data[i]; //当数据元素不等于x时，将当前元素前移至k的位置
            k++;
        }
    }
    L->length = k;
    return OK;
}

int question6(SqList *L) {
    if (L->length < 1) {
        printf("Error\n");
        return ERROR;
    }
    //使用辅助变量cur标记当前相同的值
    ElemType cur = L->data[0];
    int k = 1; //记录不相等的元素个数
    for (int i = 1; i < L->length; i++) {
        if (L->data[i] != cur) {
            L->data[k++] = L->data[i]; //将不重复的元素前移
            cur = L->data[i];
        }
    }
    L->length = k;
    return OK;
}

SqList question7(SqList L1, SqList L2) {
    SqList res;
    InitList(&res);
    int i = 0, j = 0; //创建两个游标
    while (i < L1.length && j < L2.length) {
        int tmp;
        //从大到小排列
        if (L1.data[i] > L2.data[j]) {
            tmp = L2.data[j++];
        } else {
            tmp = L1.data[i++];
        }
        res.data[res.length++] = tmp; //较小的元素存入res
    }
    while (i < L1.length) {
        res.data[res.length++] = L1.data[i++];
    }
    while (j < L2.length) {
        res.data[res.length++] = L2.data[j++];
    } //将没有遍历完的元素放在res的最后面
    return res;
}

void question8(ElemType *arr, int m, int n) {
    int tmp[MAXSIZE];
    int length;
    for (int i = 0; i < m; i++) {
        tmp[i] = arr[i];
    } //保存前m个元素
    for (int i = 0; i < m + n; i++) {
        if (i < n) {
            arr[i] = arr[m + i]; //将后n个元素前移
        } else {
            arr[i] = tmp[i - n]; //将tmp数组中的m个元素填充到后m个位置
        }
    }
}

void question82(ElemType *arr, int m, int n) {
    Reverse(arr, 0, m + n); //将整个数组逆置
    Reverse(arr, 0, n);     //将前n个元素逆置
    Reverse(arr, n, m + n); //将后m个元素逆置
}

int question9(SqList *L, ElemType x) {
    if (L->length < 1) {
        printf("空表\n");
        return ERROR;
    }
    //创建一个辅助变量记录第一个不小于x的元素下标
    int index = -1;
    //使用折半查找
    int l = 0, r = L->length - 1;
    while (l <= r) { //添加=为了判断l和r处是否满足
        index = (r + l) / 2;
        if (L->data[index] == x) {
            break; //等于x时退出循环
        } else if (L->data[index] < x) {
            l = index + 1; //当小于x时，表明x在右侧
        } else {
            r = index - 1; //当大于x时，表明x在左侧
        }
    }

    if (L->data[index] == x) {
        if (index >= L->length - 1) {
            printf("Error\n");
            return ERROR;
        } //当index大于数组长度或处于最后一个元素时，失败
        swap(&L->data[index], &L->data[index + 1]); //交换index和后面元素的值
    } else {
        if (L->length == MAXSIZE) {
            printf("Error\n");
            return ERROR;
        } //当数组已满时，错误，无法插入
        for (int i = L->length; i > index; i--) {
            L->data[i] = L->data[i - 1];
        }                   // index及之后的元素全部后移一位
        L->data[index] = x; // index填入x
        L->length++;
    }
    return OK;
}

int question12(SqList L) {
    if (L.length < 1) {
        return ERROR;
    }
    //当存在主元素时，出现的次数> n/2+1，
    //所以当遍历数组时，相同+1，不同-1，主元素的次数必然>0
    //<=0的情况必然不是主元素
    //>0是必然条件，所以必须重新遍历数组判断是否为主元素
    int count = 0; //计数，相同+1，不同-1
    int tmp = -1;
    for (int i = 0; i < L.length; i++) {
        if (count == 0) {
            tmp = L.data[i]; // count==0时，tmp记为当前数据元素
            count++;
        } else {
            if (L.data[i] == tmp) {
                count++;
            } else {
                count--;
            }
        }
    }
    if (count > 0) {
        int c = 0;
        for (int i = 0; i < L.length; i++) {
            if (L.data[i] == tmp) {
                c++;
            }
        } //判断是否满足主元素的条件
        if (c > L.length / 2) {
            return tmp;
        } //当满足条件时，返回主元素
    }
    return -1; //不满足返回-1
}

int GetMinElem(SqList *L) {
    int res = -1, minValue = 10000;
    for (int i = 0; i < L->length; i++) {
        if (minValue > L->data[i]) {
            minValue = L->data[i]; //更新最小元素值
            res = i;
        }
    }
    return res; //返回下标
}

void swap(ElemType *a, ElemType *b) {
    ElemType tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Reverse(ElemType *arr, int right, int left) {
    left--;
    while (right < left) {
        swap(&arr[right++], &arr[left--]);
    }
}

void TestQuestion6() {
    SqList L;
    int arr[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, -1};
    InitListArray(&L, arr);
    printList(L);
    question6(&L);
    printList(L);
}

void TestQuestion7() {
    SqList L1, L2;
    int arr1[] = {1, 3, 5, -1};
    int arr2[] = {2, 4, 6, -1};
    InitListArray(&L1, arr1);
    InitListArray(&L2, arr2);
    printList(L1);
    printList(L2);
    printList(question7(L1, L2));
}

void TestQuestion8() {
    int arr[10] = {8, 9, 10, 1, 2, 9, 4, 5, 6, 7};
    question82(arr, 3, 7);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void TestQuestion10() {
    SqList L;
    int arr[10] = {1, 2, 5, 5, 5, 5, 4, 5, 5, -1};
    InitListArray(&L, arr);
    int res = question12(L);
    if (res == -1) {
        printf("没有主元素\n");

    } else {
        printf("主元素：%d\n", res);
    }
}
