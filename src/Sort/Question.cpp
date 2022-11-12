#include "Function.h"
#include <iostream>

void question2(ElemType A[], int n)
{
    int low = 1, high = n;
    bool flag = false;
    while (low < high)
    {
        for (int i = 1; i < high; ++i)
        {
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                flag = true;
            }
        }
        high--;
        for (int i = high; i > low; --i)
        {
            if (A[i] < A[i - 1])
            {
                swap(A[i], A[i - 1]);
                flag = true;
            }
        }
        low++;
        if (flag == false)
            return;
    }
}

void question3(ElemType A[], int n)
{
    //基于快速排序，将奇数与偶数对换
    int index = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (A[i] % 2 == 0)
        {
            index = i;
            break;
        }
    }
    if (index == 0)
        return; //表示全是奇数
    int low = 1, high = n;
    ElemType pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] % 2 == 0)
        {
            //将从后往前的第一个奇数移动到前面
            --high;
        }
        A[low] = A[high];
        while (low < high && A[low] % 2 == 1)
        {
            ++low;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
}

int question5(ElemType A[], int n, int k)
{
    //使用冒泡排序，从小到大排序，遍历k次
    bool flag = false;
    int count = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = n; j > i; --j)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                flag = true;
            }
        }
        if (++count == k || flag == false)
            break;
    }
    return A[k];
}

int question5_2(ElemType A[], int low, int high, int k)
{
    int i = low, j = high;
    int pivot = A[i];
    while (i < j)
    {
        while (i < j && A[j] >= pivot)
        {
            --j;
        }
        A[i] = A[j];
        while (i < j && A[i] <= pivot)
        {
            ++i;
        }
        A[j] = A[i];
    }
    A[i] = pivot;
    //以上是一次划分

    if (i == k)
    {
        return A[i]; //当i==k时，直接输出A[i]
    }
    else if (i < k)
    {
        return question5_2(A, i + 1, high, k);
    }
    else
    {
        return question5_2(A, low, i - 1, k);
    }
}