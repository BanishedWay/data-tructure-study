#define MaxSize 100

typedef int ElemType;
typedef struct {
    ElemType data;
    int parent; //双亲指针域
} PTNode;

typedef struct {
    PTNode nodes[MaxSize];
    int n;
} PTree; //双亲表示法

struct CTNode {
    int child;           //孩子结点在数组中的位置
    struct CTNode *next; //下一个孩子
};

typedef struct {
    ElemType data;
    struct CTNode *firstchild; //指向第一个孩子
} CTBox;

typedef struct {
    CTBox nodes[MaxSize];
    int n, r; //结点数目和根结点的位置
} CTree;    //孩子表示法

typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling; //存储第一个孩子和右兄弟
} CSNode, *CSTree;                         //孩子兄弟表示法
