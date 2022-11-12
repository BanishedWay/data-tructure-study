#include "Function.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void print(ElemType A[], int n)
{
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void InsertSort(ElemType A[], int n)
{
    //实现插入排序
    //将A[0]作为哨兵
    int i, j;
    for (i = 2; i <= n; ++i)
    { //从第二个元素开始往后遍历排序
        if (A[i] < A[i - 1])
        {
            A[0] = A[i]; //将A[0]暂存元素
            for (j = i - 1; A[0] < A[j]; --j)
            {
                //从i-1开始往前找到第一个比A[0]小的元素
                A[j + 1] = A[j]; //比A[0]大的元素都后移一位
            }
            //停止时A[0]>=A[j]
            A[j + 1] = A[0];
        }
    }
}

void InsertSortBinary(ElemType A[], int n)
{
    //首先通过二分查找找到需要插入的位置
    int i, j, low, high, mid;
    for (i = 2; i <= n; ++i)
    {
        A[0] = A[i];
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            low = 1;
            high = i - 1;
            while (low <= high)
            {
                mid = (low + high) / 2;
                if (A[mid] > A[0])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            } //二分查找找到不小于A[0]的位置在high+1(即low)处
            for (j = i - 1; j >= low; --j)
            {
                A[j + 1] = A[j];
            }
            //元素后移，插入
            A[low] = A[0];
        }
    }
}

void ShellSort(ElemType A[], int n)
{
    //希尔排序
    int i, j;
    for (int d = n / 2; d >= 1; d /= 2)
    {
        for (i = d + 1; i <= n; ++i)
        {
            if (A[i] < A[i - d])
            {
                A[0] = A[i];
                for (j = i - d; j >= 1 && A[j] > A[0]; j -= d)
                {
                    A[j + d] = A[j];
                }
                A[j + d] = A[0];
            }
        }
    }
}

void swap(ElemType &a, ElemType &b)
{
    ElemType tmp = a;
    a = b;
    b = tmp;
}

void BubbleSort(ElemType A[], int n)
{
    for (int i = 1; i <= n - 1; ++i)
    {
        bool flag = false;
        for (int j = n; j > i; --j)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j], A[j - 1]);
                flag = true;
            } //标记存在交换
        }     //从前往后，将相邻的两个元素根据比较结果交换次序
        if (!flag)
        {
            return;
        }
    }
}

void SelectSort(ElemType A[], int n)
{
    int minIndex;
    for (int i = 1; i < n; ++i)
    {
        minIndex = i;
        for (int j = n; j > i; --j)
        {
            if (A[minIndex] > A[j])
            {
                minIndex = j;
            }
        } //从后往前遍历，比较每个元素与最小元素的值，找到最小元素的位置
        if (i != minIndex)
            swap(A[i], A[minIndex]);
    }
}

void QuickSort(ElemType A[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = partition(A, low, high); //此时A[mid]已经到了最终的位置上
    QuickSort(A, low, mid - 1);        //递归处理小于A[mid]的数组
    QuickSort(A, mid + 1, high);       //递归处理大于A[mid]的数组
}

//空间复杂的：最坏O(n)，平均O(log n)
//时间复杂度：O(nlog n)
//快速排序是所有内部排序中平均性能最优的算法
int partition(ElemType A[], int low, int high)
{
    //每一次划分都将一个元素放到最终位置上
    //将数组分为两个部分
    int pivot = A[low]; //记录数轴元素
    if (low < high)
    {
        while (low < high)
        {
            while (low < high && A[high] >= pivot)
            {
                --high;
            }
            A[low] = A[high]; //将第一个小于枢轴的元素交换到low的位置
            while (low < high && A[low] <= pivot)
            {
                ++low;
            }
            A[high] = A[low]; //将第一个大于枢轴的元素交换到high的位置
        }
        //循环结束时，low==high，该位置也是枢轴元素最终存放的位置
        A[low] = pivot;
    }
    return low;
}

void HeapAdjust(ElemType A[], int k, int n)
{
    //在大根堆中，以k为根节点的树被破坏
    A[0] = A[k];
    for (int i = 2 * k; i <= n; i *= 2)
    {
        if (i < n && A[i] < A[i + 1])
        {
            //选择两个孩子中最大的一个
            ++i;
        }
        if (A[0] < A[i])
        {
            A[k] = A[i];
            k = i;
        }
        else
        {
            break;
        } //满足大根堆条件时直接退出
    }
    A[k] = A[0];
}

void BuildHeap(ElemType A[], int n)
{
    for (int i = n / 2; i > 0; --i)
    {
        HeapAdjust(A, i, n);
    } //从最后一个非叶结点开始建立大根堆
}

void HeapSort(ElemType A[], int n)
{
    BuildHeap(A, n); //建立大根堆
    for (int i = n; i > 1; --i)
    {
        swap(A[1], A[i]);        //将堆顶与i交换
        HeapAdjust(A, 1, i - 1); //剩余元素进行调整
    }
}

void Merge(ElemType A[], int low, int mid, int high)
{
    ElemType *B = (ElemType *)malloc(sizeof(ElemType) * high + 1);
    //构建辅助数组

    for (int i = low; i <= high; ++i)
    {
        B[i] = A[i];
    }
    int i, j, k;
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; ++k)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i++];
        }
        else
        {
            A[k] = B[j++];
        }
    }
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= high)
    {
        A[k++] = B[j++];
    }
}

void MergeSort(ElemType A[], int n)
{
    merge(A, 1, n);
}

void merge(ElemType A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge(A, low, mid);
        merge(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}
