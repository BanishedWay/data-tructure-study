#define MAXN 255

typedef struct
{
    char ch[MAXN];
    int length;
} SString;

typedef struct
{
    char *ch;
    int length;
} HString;

//多项式的定义
typedef struct PolyNode
{
    int coef; //系数
    int expn; //指数
    struct PolyNode *next;
} PolyNode, *PolyList;

void createPolyList(PolyList &L, int n);

int index(SString S, SString T);
void get_next(SString T, int next[]);