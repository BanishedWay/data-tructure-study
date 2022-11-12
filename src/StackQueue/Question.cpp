#include "Stack.h"
#include "Queue.h"
#include <cstdio>

bool question3(int A[])
{
    int i = 0;
    SqStack S;
    InitStack(S);
    int tmp;
    while (A[i] != '\0')
    {
        switch (A[i])
        {
        case 1:
            Push(S, 1);
            break;
        case 0:
            if (Empty(S))
            {
                printf("error");
                break;
            }
            else
                Pop(S, tmp);
            break;
        }
        ++i;
    }
    return Empty(S);
}

int question3_3(int n, int x)
{
    if (n == 0)
        return 1;
    else if (n == 1)
    {
        return 2 * x;
    }
    else
    {
        return x * x * question3_3(n - 1, x) - 2 * (n - 1) * question3_3(n - 2, x);
    }
}

void question3_4()
{
    SqQueue q;  //轮船等待队列
    SqQueue q1; //客车等待队列
    SqQueue q2; //货车等待队列
    //当客车充足且不够四辆时，客车上船
    //当客车四辆，且货车等待队列不空时，货车上一辆
    //当客车不足且货车等待队列不空时，货车代替客车补齐4辆或者直到队列空
    int i = 0, j = 0;
    int tmp;
    while (j < 10)
    {
        if (i < 4 && !Empty(q1))
        {
            EnQueue(q, 1);
            DeQueue(q1, tmp);
            ++i;
            ++j;
        }
        else if (i == 4 && !Empty(q2))
        {
            EnQueue(q, 0);
            DeQueue(q2, tmp);
            ++j;
            i = 0; //重新开始计数
        }
        else
        {
            while (j < 10 && i < 4 && !Empty(q2))
            {
                EnQueue(q, 0);
                DeQueue(q2, tmp);
                ++j;
                ++i; //保证i不会大于4
            }
        }
        if (Empty(q1) && Empty(q2))
        {
            break;
        }
    }
}