#include "Stack.h"

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool Empty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack &S, ElemType x)
{
    if (S.top == MaxSize - 1)
    {
        return false; //栈满
    }
    S.data[++S.top] = x; //指针+1，入栈
    return true;
}

bool Pop(SqStack &S, ElemType &x)
{
    if (Empty(S))
    {
        return false;
    }
    x = S.data[S.top--]; //出栈，top-1
    return true;
}

ElemType GetTop(SqStack &S, ElemType &x)
{
    if (Empty(S))
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

void InitShStack(ShStack &S)
{
    S.top0 = -1;
    S.top1 = MaxSize;
}

bool EqualBracket(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            Push(S, str[i]);
        }
        else
        {
            if (Empty(S))
            {
                return false; //栈空，即右括号单身
            }
            char top;
            Pop(S, top); //栈顶元素出栈，判断是否匹配
            if (str[i] == ']' && top != '[')
            {
                return false;
            }
            if (str[i] == ')' && top != '(')
            {
                return false;
            }
            if (str[i] == '}' && top != '{')
            {
                return false;
            }
        }
    }
    return Empty(S); //判断是否为空，非空表示存在未匹配的括号
}
