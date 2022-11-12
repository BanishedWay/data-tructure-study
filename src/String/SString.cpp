#include "SString.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int index(SString S, SString T)
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            //字符相等时
            ++i;
            ++j; //同步后移
        }
        else
        {
            i = i - j + 2; //因为从1开始，i和j是进行j-1次加法操作
            j = 1;
        }
    }
    if (j > T.length)
    {
        return i - T.length; //表明j遍历完了T中所有的字符
    }
    return -1;
}

int index_KMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        } //当元素相等时，同步后移
        else
        {
            j = next[j];
            // next数组保存的是当第j个位置出现不匹配时，应该将子串后移到的位置
        }
        if (j > T.length)
        {
            return j - T.length;
        }
        return -1;
    }
}

void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j; // next[j+1]=next[j]
        }
        else
        {
            j = next[j]; //否则循环继续，继续比较next[j]的字符串
        }
    }
}

void get_nextVal(SString T, int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            if (T.ch[i] != T.ch[j])
            {
                //与前一个元素不相等时
                nextval[i] = j; //正常的求next方法
            }
            else
            {
                nextval[i] = nextval[j]; //否则与前一个的nextval相等
            }
        }
    }
}

void createPolyList(PolyList &L, int n)
{
    int i;
    PolyList p, q;
    L = (PolyNode *)malloc(sizeof(PolyNode));
    L->next = NULL;
    q = L;
    for (i = 1; i <= n; i++)
    {
        p = (PolyNode *)malloc(sizeof(PolyNode));
        cin >> p->coef >> p->expn;
        q->next = p;
        q = q->next;
    }
    p->next = NULL;
}
