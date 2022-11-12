#include "BiTree.h"
#include <iostream>
#include <stack>

using namespace std;

void visit(BiTNode *p)
{
    cout << p->data << " ";
}
void PreOrderTraverse(BiTree T)
{
    stack<BiTNode *> stack;
    stack.push(T);
    BiTNode *p = T;
    while (p && !stack.empty())
    {
        p = stack.top();
        stack.pop();
        cout << p->data << " ";
        if (p->rchild)
        {
            stack.push(p->rchild);
        }
        if (p->lchild)
        {
            stack.push(p->lchild);
        }
    }
}

void InOrderTraverse(BiTree T)
{
    stack<BiTNode *> stack;
    BiTNode *p = T;
    while (p || !stack.empty())
    {
        if (p)
        {
            stack.push(p);
            p = p->lchild;
        }
        else
        {
            p = stack.top();
            stack.pop();
            visit(p);
            if (p->rchild)
            {
                p = p->rchild;
            }
        }
    }
}

void PostOrder(BiTNode *T)
{
    stack<BiTNode *> stack;
    BiTNode *p = T, *prev = NULL;
    while (p || !stack.empty())
    {
        if (p)
        {
            stack.push(p);
            p = p->lchild;
        }
        else
        {
            p = stack.top();
            if (p->rchild == NULL || prev == p->rchild)
            {
                p = stack.top();
                stack.pop();
                visit(p);
                prev = p;
                p = NULL;
            }
            else
            {
                p = p->rchild;
            }
        }
    }
}