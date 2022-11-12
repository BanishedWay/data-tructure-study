typedef struct GLNode
{
    int tag; //用于区分表结点还是原子结点
    union {
        int atom;
        struct
        {
            struct GLNode *hp, *tp;
        } ptr; // ptr是指针域，hp和tp分别指向表头和表尾
    };
} * GList;

typedef struct GLNode1
{
    int tag;
    union {
        int atom;
        struct GLNode *hp; //表结点的表头指针
    };
    struct GLNode *tp; //相当于线性链表的next
} GLNode1;
