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

int index(SString S, SString T);
void get_next(SString T, int next[]);