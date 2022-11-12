#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize]; //静态列表存储
    int top;                //栈顶指针
} SqStack;

typedef struct
{
    ElemType data[MaxSize];
    int top0;
    int top1;
} ShStack;

void InitStack(SqStack &S);
bool Empty(SqStack S);

bool Push(SqStack &S, ElemType x);
bool Pop(SqStack &S, ElemType &x);

ElemType GetTop(SqStack &S, ElemType &x);

void InitShStack(ShStack &S);

bool EqualBracket(char str[], int length);
