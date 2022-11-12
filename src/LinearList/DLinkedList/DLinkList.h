#define True 1
#define False 0
#define MAXSIZE 10
typedef int Bool;

typedef int ElemType;

typedef struct DNode {
    ElemType data;
    struct DNode *next, *prior;
} DNode, *DLinkList;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//静态链表
typedef struct {
    ElemType data;
    int next;
} SLinkList[MAXSIZE];

//初始化
DLinkList InitDLinkList();
LinkList InitLinkList();
//判空
Bool IsEmpty(DLinkList L);
Bool IsEmptyLinkList(LinkList L);
//判断是否为表尾结点
Bool IsTail(LinkList L, LNode *p);
//指定结点插入
Bool InsertNextNode(DNode *p, DNode *q);
//指定结点删除后继结点
Bool DeleteNode(DNode *p);
//打印来链表
void PrintList(DLinkList L);
