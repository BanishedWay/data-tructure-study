#include "Sort.h"
#include <cstdlib>

void InsertSort(int A[], int n)
{
    int i = 0, j = 0, low, high, mid;
    for (i = 1; i < n; i++)
    {
        if (A[i] < A[i - 1])
        {
            //如果A[1]小于前驱，表明当前元素应该插入到前面已经排序的序列中
            int temp = A[i];
            for (j = i - 1; j >= 0 && A[j] > temp; j--)
            {
                //从后往前依次寻找第一个不大于temp的元素
                //遍历过程中，每个元素后移一位
                A[j + 1] = A[j];
            }                //结束时A[j]<=原先的A[i]
            A[j + 1] = temp; //最后将temp插入到不大于temp的元素后面一位
            /*  low = 1, high = i - 1;
             while (low <= high) {
                 mid = (low + high) / 2;
                 A[mid] > temp ? high = mid - 1 : low = mid + 1;
             }
             for (j = i - 1; j >= high; j--) {
                 A[j + 1] = A[j];
             }
             A[high + 1] = temp; */
            //使用折半查找的方式
        }
    }
}

void ShellSort(int A[], int n)
{
    int d, i, j;
    for (d = n / 2; d >= 1; d /= 2)
    { //间隔为d，每次循环减半
        for (i = d + 1; i <= n; i++)
        { //从d+1个元素开始遍历，插入的元素间隔为d
            if (A[i] < A[i - d])
            { //当子表中元素小于前驱时，进行插入排序
                A[0] = A[i];
                for (j = i - d; j >= 1 && A[j] > A[0]; j -= d)
                {
                    A[j + d] = A[j];
                }                //将前面大于A[i]的元素全部后移d位
                A[j + d] = A[0]; //将A[i]插入到j+d的位置（此时j<=0或A[j]<=A[i]
            }
        }
    }
}

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        bool flag = false; //标记是否发生交换
        for (int j = n - 1; j > i; --j)
        { //从后往前交换顺序
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                flag = true;
            } //每次将第i个元素之后的元素的最小元素移动到第i+1个位置（后面的元素冒泡到前面）
        }
        if (!flag)
        {
            return; //没有发生交换，则表示表已经有序
        }
    }
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void QuickSort(int A[], int low, int high)
{
    if (low >= high)
        return;
    int mid = partition(A, low, high); //确定一次划分得到的枢轴位置
    QuickSort(A, low, mid - 1);        //对左子表进行划分
    QuickSort(A, mid + 1, high);       //对右子表进行划分
}

int partition(int A[], int low, int high)
{
    int pivot = A[low]; //暂存low指向的元素
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
        {
            high--;
        }                 //找到右边第一个小于枢轴的元素
        A[low] = A[high]; //将该元素保存到low的位置（因为此时low的位置是空的）
        while (low < high && A[low] <= pivot)
        {
            low++;
        }                 //从前往后找到第一个大于枢轴的元素
        A[high] = A[low]; //保存到high的位置（此时high为空）
    }                     //循环将所有元素摆放在枢轴左右两侧
    A[low] = pivot;       //将枢轴元素存放到最终位置
    return low;           //此时low==high，指向枢轴元素在数组中的位置
}

void SelectSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; //找到i后的最小元素（包括i）
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        } //比较找到未排序序列中最小的元素
        if (minIndex != i)
        { //如果minIndex==i，则表明后面的元素都小于当前元素
            swap(A[i], A[minIndex]);
        } //将该元素插入到当前已排序序列的后面
    }
}

void BuildMaxHeap(int A[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {                        //下标从1开始
        HeapAdjust(A, i, n); //从后往前调整大根堆
    }
}

void HeapAdjust(int A[], int k, int len)
{
    A[0] = A[k];
    for (int i = 2 * k; i <= len; i = i * 2)
    { //沿着子树开始寻找
        if (i < len && A[i] < A[i + 1])
        {
            i++; //当i<len时，才会存在右孩子
        }        //判断左右孩子的最大值

        if (A[0] >= A[i])
        { //判断是否满足大根堆的条件
            break;
        }
        else
        { //不满足则交换父结点和孩子的值
            A[k] = A[i];
            k = i; //判断把父结点放在i位置时，是否会出现递归子树不符合大根堆
        }
    }
    A[k] = A[0]; //最后将最顶端的元素下坠到合适的位置
}

void HeapSort(int A[], int n)
{
    BuildMaxHeap(A, n); //建立大根堆
    for (int i = n; i > 1; i--)
    {                            //进行n-1次排序
        swap(A[i], A[1]);        //将堆顶元素交换到末尾
        HeapAdjust(A, 1, i - 1); //对剩余元素的堆顶元素进行调整
    }
}

/**
 * 归并排序的思路是：
 * 递归对左右两个子序列进行归并
 * 在递归的顶层，左右序列只有一个元素，此时只需要对比两个元素的值即可完成排序
 */
void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);      //对左序列进行归并
        MergeSort(A, mid + 1, high); //对右序列进行归并
        Merge(A, low, mid, high);    //将归并后的两个有序序列合并为一个序列
    }
}

void Merge(int A[], int low, int mid, int high)
{
    int *B = (int *)malloc(sizeof(int) * (high + 1));
    for (int i = low; i <= high; i++)
    {
        B[i] = A[i];
    } //首先将待排序序列复制到B
    int k, i, j;
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high;)
    {
        if (B[i] <= B[j])
        {
            A[k++] = B[i++];
        }
        else
        {
            A[k++] = B[j++];
        }
    } //从左右两个子序列中进行归并，将结果放入A中
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= high)
    {
        A[k++] = B[j++];
    } //将剩余列表中没有进行比较的元素直接放入后面
}
