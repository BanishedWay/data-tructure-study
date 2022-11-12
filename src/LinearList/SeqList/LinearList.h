#define MAXSIZE 15 //定义最大长度
#define OK 1
#define ERROR 0
typedef int ElemType;

typedef struct StaticList {
    ElemType data[MAXSIZE]; //静态数组存储数据元素
    int length;             //当前长度
} SqList;                 //顺序表的类型定义

typedef struct DynamicList {
    ElemType *data; //动态数组存储数据元素
    int maxSize;    //当前数组最大长度
    int length;     //当前数据元素长度
} SeqList;
//初始化一个列表
int InitList(SqList *L);
//初始化动态列表
int InitDynamicList(SeqList *L);
//修改动态列表长度
int IncreaseDynamicList(SeqList *L, int len);
//插入操作
int ListInsert(SqList *L, int i, ElemType e);
//删除操作
int ListDelete(SqList *L, int i, ElemType *e);
//按位查找
ElemType GetElem(SqList L, int i);
//按值查找
int LocateElem(SqList L, ElemType e);
//打印线性表
int printList(SqList L);
//从数组初始化线性表
int InitListArray(SqList *L, ElemType *arr);
