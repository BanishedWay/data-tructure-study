// 复现Sort算法
typedef int ElemType;

void print(ElemType A[], int n);

void InsertSort(ElemType A[], int n);

void InsertSortBinary(ElemType A[], int n);

void ShellSort(ElemType A[], int n);

void BubbleSort(ElemType A[], int n);

void swap(ElemType &a, ElemType &b);

void SelectSort(ElemType A[], int n);

void QuickSort(ElemType A[], int low, int high);
int partition(ElemType A[], int low, int high);

//堆排序
void BuildHeap(ElemType A[], int n);
void HeapAdjust(ElemType A[], int k, int n);
void HeapSort(ElemType A[], int n);

//归并排序
void Merge(ElemType A[], int low, int mid, int high);
void MergeSort(ElemType A[], int n);
void merge(ElemType A[], int low, int high);