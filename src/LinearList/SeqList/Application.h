#include "LinearList.h"

int question1(SqList *L);
//数组逆置，空间复杂度为O(1)
int question2(SqList *L);
//删除x的元素
int question3(SqList *L, ElemType x);
//删除在s,t之间的元素
int question4(SqList *L, ElemType s, ElemType t);
//删除在s,t之间的元素
int question5(SqList *L, ElemType s, ElemType t);
//删除重复元素
int question6(SqList *L);
//合并有序表
SqList question7(SqList L1, SqList L2);
//交换数组位序
void question8(ElemType *arr, int m, int n);
void question82(ElemType *arr, int m, int n);
//寻找x
int question9(SqList *L, ElemType x);
//寻找主元素
int question12(SqList L);

//获取最小值下标
int GetMinElem(SqList *L);
//交换次序
void swap(ElemType *a, ElemType *b);
//逆序
void Reverse(ElemType *arr, int right, int legt);

// Test functions
void TestQuestion6();
void TestQuestion7();
void TestQuestion8();
void TestQuestion10();
