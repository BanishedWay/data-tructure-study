#define True 1
#define False 0
typedef int Bool;
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList InitLinkList();
void PrintList(LinkList L);
Bool IsEmpty(LinkList L);
int Length(LinkList L);

//按位查找
LNode *GetElem(LinkList L, int i);
//按值查找
LNode *LocateElem(LinkList L, ElemType x);
/**插入**/
//按位序插入
Bool ListInsert(LinkList L, int i, ElemType x);
//指定结点后插操作
Bool InsertNextNode(LNode *p, ElemType x);
//指定结点前插操作
Bool InsertPrevNode(LNode *p, ElemType x);
/**删除**/
//按位序删除
Bool ListDelete(LinkList L, int i, ElemType *e);
//删除指定结点
Bool DeleteNode(LNode *p);
//获取长度
int GetLength(LinkList L);
//相等
Bool equal(LinkList L1, LinkList L2);
/**建立**/
//尾插法
LinkList ListTailInsert(ElemType *arr, int length);
//头插法
LinkList ListHeadInsert(ElemType *arr, int length);
