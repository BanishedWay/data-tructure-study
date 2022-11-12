#define MaxSize 100
typedef int ElemType;

typedef struct SqTreeNode
{
    ElemType data;
    bool isEmpty;
} SqTree[MaxSize];

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 0表示指向孩子，1表示线索化
} ThreadNode, *ThreadTree;

typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

void InitBiTree(BiTree root);

void PreOrder(BiTree T);
void InOrder(BiTree T);
void PostOrder(BiTree T);

//非递归遍历
void PreOrderTraverse(BiTree T);
void InOrderTreverse(BiTree T);
void PostOrderTraverse(BiTree T);

void visit(BiTNode *node);

void CreateInThread(ThreadTree T);
void InThread(ThreadTree &T, ThreadTree &prev);
ThreadNode *NextThreadInNode(ThreadNode *p);
ThreadNode *InFirstNode(ThreadNode *p);
void InOrder(ThreadTree T);
ThreadNode *InLastNode(ThreadNode *p);
ThreadNode *PrevThreadInNode(ThreadNode *p);
void InOrderReverse(ThreadTree T);

void CreatePreThread(ThreadTree T);
void PreThread(ThreadTree &T, ThreadTree &prev);
ThreadNode *PreFirstNode(ThreadNode *p);
ThreadNode *NextThreadPreNode(ThreadNode *p);

void CreatePostThread(ThreadTree T);
void PostThread(ThreadTree &T, ThreadTree &prev);
ThreadNode *PostLastNode(ThreadNode *p);
ThreadNode *PrevThreadPostNode(ThreadNode *p);

BSTNode *BST_Search(BSTree T, int key);
bool BST_Insert(BSTree &T, int key);
