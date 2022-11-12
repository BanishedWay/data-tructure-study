#define MaxVerNum 100
typedef char ElemType;

//邻接矩阵
typedef struct
{
    ElemType Vex[MaxVerNum];        //顶点表
    int Edge[MaxVerNum][MaxVerNum]; //邻接矩阵
    int vexnum, arcnum;
} MGraph;

//邻接表
typedef struct ArcNode
{
    int adjvex;           //边/弧指向的顶点
    struct ArcNode *next; //指向下一条边的指针
} ArcNode;

typedef struct VNode
{
    ElemType data;
    ArcNode *first; //指向第一条边的指针
} VNode, AdjList[MaxVerNum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

//十字链表法
typedef struct ArcBox
{
    ElemType tailvex, headvex;          //弧的尾顶点和头顶点
    struct ArcBox *taillink, *headlink; //指向下一个弧头和弧尾相同的指针
    int info;
} ArcBox; //边结点

typedef struct VexNode
{
    ElemType data;
    ArcBox *firstin, *firstout; //分别指向第一条入弧和出弧

} VexNode; //顶点结点

typedef struct
{
    VexNode nodes[MaxVerNum];
    int vexnum, edgenum;
} OLGraph; //十字链表
//从i指向j的弧结点同时存在于i的尾链表和j的头链表，可以同时赋值

ElemType FirstNeighbor(MGraph G, ElemType v);
ElemType NextNeighbor(MGraph G, ElemType v, ElemType w);
void BFS(MGraph G, ElemType v);
void BFSTraverse(MGraph G);
void visit(ElemType v);
void DFS(MGraph G, ElemType v);
void DFSTraverse(MGraph G);

void Dijstra(MGraph G, ElemType v);
