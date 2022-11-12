#define MAXSIZE 10

typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int front, rear; //队头指针和队尾指针
} SqQueue;

typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front, *rear;
} LinkQueue;

void InitQueue(SqQueue &Q);
bool Empty(SqQueue Q);
bool EnQueue(SqQueue &Q, ElemType x);
bool DeQueue(SqQueue &Q, ElemType &x);
bool GetHead(SqQueue Q, ElemType &x);

void InitLinkQueue(LinkQueue &Q);
bool EmptyLink(LinkQueue &Q);
void EnLinkQueue(LinkQueue &Q, ElemType x);
void DeLink(LinkQueue &Q, ElemType &x);
