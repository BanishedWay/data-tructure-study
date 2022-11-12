//插入排序
void InsertSort(int A[], int n);
//希尔排序
void ShellSort(int A[], int n);
//冒泡排序
void BubbleSort(int A[], int n);
//快速排序
void QuickSort(int A[], int low, int high);
int partition(int A[], int low, int high);

void swap(int &a, int &b);

//简单选择排序
void SelectSort(int A[], int n);

/*
 * 堆排序
 * 建立大根堆
 * 堆排序
 */
void BuildMaxHeap(int A[], int n);
//将以k为根结点的子树调整为大根堆
void HeapAdjust(int A[], int k, int len);
void HeapSort(int A[], int n);

//归并排序
void MergeSort(int A[], int low, int high);
//归并两个序列
void Merge(int A[], int low, int mid, int high);
