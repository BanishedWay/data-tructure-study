typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} SSTable;

typedef struct {
    ElemType maxValue;
    int low, high;
} Index;

int SearchSeq(SSTable ST, ElemType key); //顺序查找

int SearchBinary(SSTable ST, ElemType key); //折半查找
