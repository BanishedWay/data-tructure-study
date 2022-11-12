#include "LinearList.h"
#include <cstdio>
#include <iostream>
void swap(int &a, int &b);
void invert(int a[], int low, int high);

int question1(SqList &L) {
    if (L.length == 0) {
        printf("List empty\n");
        return false;
    }
    int minValue = L.data[0], minIndex = 0;
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] < minValue) {
            minValue = L.data[i];
            minIndex = i; //更新最小值和最小索引
        }
    }
    L.data[minIndex] = L.data[L.length - 1];
    --L.length; //删除最后一个元素
    return minValue;
}
bool question2(SqList &L) {
    if (L.length == 0) {
        return false;
    }
    //逆置，空间复杂度为O(1)
    for (int i = 0; i < L.length / 2; ++i) {
        swap(L.data[i], L.data[L.length - 1 - i]); //交换第i+1个和n-i个元素
    }
    return true;
}

bool question3(SqList &L, int x) {
    if (L.length == 0) {
        return false;
    }
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == x) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
            //对每一个元素进行判断，==x则不动，计数+1，!=x则向前移动k个位置
        }
    }
    L.length -= k;
    return true;
}

bool question4(SqList &L, int s, int t) {
    if (s >= t || L.length == 0) {
        return false;
    }
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] > s && L.data[i] < t) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
            //对每一个元素进行判断，在范围内则不动，计数+1，不在范围内则向前移动k个位置
        }
    }
    L.length -= k;
    return true;
}

bool question5(SqList &L, int s, int t) {
    if (s >= t || L.length == 0) {
        return false;
    }
    int k = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] >= s && L.data[i] <= t) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
            //对每一个元素进行判断，在范围内则不动，计数+1，不在范围内则向前移动k个位置
        }
    }
    L.length -= k;
    return true;
}

bool question6(SqList &L) {
    if (L.length == 0) {
        return false;
    }
    if (L.length == 1) {
        return true;
    }
    int k = 0;
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i] == L.data[i - 1]) {
            //==前一个元素则计数+1
            k++;
        } else {
            //不等则当前元素前移k位
            L.data[i - k] = L.data[i];
        }
    }
    L.length -= k;
    return true;
}

bool question8(SqList &L, int m, int n) {
    if (L.length == 0) {
        return false;
    }

    invert(L.data, 0, L.length);
    invert(L.data, 0, n);
    invert(L.data, n, m + n);
    return true;
}

void question9(SqList &L, int x) {
    int low = 0, high = L.length - 1;
    bool flag = false;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.data[mid] > x) {
            high = mid - 1;
        } else if (L.data[mid] < x) {
            low = mid + 1;
        } else {
            flag = true;
            low = mid;
            break;
        }
    }
    if (flag) {
        swap(L.data[low], L.data[low + 1]);
    } else {
        //将x插入到high和low之间
        for (int i = L.length; i > low; ++i) {
            L.data[i] = L.data[i - 1];
        }
        L.data[low] = x;
        L.length++;
    }
    return;
}

void invert(int a[], int low, int high) {
    if (low > high) {
        return;
    }
    for (int i = low; i < high; ++i) {
        swap(a[i], a[high - i - 1]);
    }
}

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
