#include "BiTree.h"
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void visit(BiTNode *p)
{
    printf("%d ", p->data);
}

void question_3(BiTree T)
{
    //后序遍历的非递归实现
    stack<BiTNode *> stack;
    BiTNode *p = T, *prev = NULL;
    while (p || !stack.empty())
    {
        if (p != NULL)
        {
            stack.push(p);
            p = p->lchild;
        }
        else
        {
            p = stack.top();
            if (!p->rchild || p->rchild == prev)
            {
                p = stack.top();
                stack.pop();
                visit(p);
                prev = p; //标明上次访问的结点
                p = NULL;
                //注：访问一个结点，意味着以该结点为根结点的二叉树已经完全遍历
                //如果不将p设置为NULL，则接下来p就会满足第一个循环条件，会继续添加已经访问过的左子树，因此，需要将p设置为NULL，使得下一步去判断栈顶结点
            }
            else
            {
                //当右孩子存在且未访问时
                p = p->rchild;
            }
        }
    }
}

void question4(BiTree T)
{
    //逆层序遍历
    stack<BiTNode *> stack;
    queue<BiTNode *> queue;
    BiTNode *p = T;
    queue.push(T);
    while (!queue.empty())
    {
        p = queue.front();
        queue.pop();
        stack.push(p);
        if (p->lchild)
        {
            queue.push(p->lchild);
        }
        if (p->rchild)
        {
            queue.push(p->rchild);
        }
    }
    while (!stack.empty())
    {
        p = stack.top();
        visit(p);
        stack.pop();
    }
}

int question5(BiTree T)
{
    queue<BiTNode *> queue;
    BiTNode *p = T;
    queue.push(T);
    int h = 0;
    while (!queue.empty())
    {
        int i = queue.size();
        while (i--)
        {
            p = queue.front();
            queue.pop();
            if (p->lchild)
            {
                queue.push(p->lchild);
            }
            if (p->rchild)
            {
                queue.push(p->rchild);
            }
        }
        h++;
    }
    return h;
}

int question5_2(BiTree T)
{
    BiTNode *queue[MaxSize];
    int front = -1, rear = -1, level = 0, last = 0;
    // last指向一层的最后一个结点
    queue[++rear] = T;
    BiTNode *p;
    while (front < rear)
    {
        p = queue[++front];
        if (p->lchild)
        {
            queue[++rear] = p->lchild;
        }
        if (p->rchild)
        {
            queue[++rear] = p->rchild;
        }
        if (front == last)
        {
            //此时一层的结点全部输出
            level++;
            last = rear;
        }
    }
    return level;
}

bool question7(BiTree T)
{
    //完全二叉树空结点之后不存在结点，所有结点都是连续的
    queue<BiTNode *> queue;
    queue.push(T);
    BiTNode *p;
    while (!queue.empty())
    {
        p = queue.front();
        queue.pop();
        if (p)
        {
            queue.push(p->lchild);
            queue.push(p->rchild);
        }
        else
        {
            //出现空结点
            while (!queue.empty())
            {
                p = queue.front();
                queue.pop();
                if (p)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// Search Question
int question7(BSTree T, int x)
{
    //当key!=指定data时，层次加1
    //每次比较不相等时，都会进入下一层
    int level = 1;
    while (!T && T->data != x)
    {
        if (x < T->data)
        {
            T = T->lchild;
        }
        else
        {
            T = T->rchild;
        }
        level++;
    }
    return level;
}

bool question6(BSTree T)
{
    //对二叉排序树进行中序遍历，如果每次的结果都大于前一个，就是二叉排序树

    stack<BSTNode *> S;
    int minValue = -1;
    while (!T || !S.empty())
    {
        if (!T)
        {
            S.push(T);
            T = T->lchild;
        }
        else
        {
            T = S.top();
            S.pop();
            if (minValue > T->data)
            {
                return false;
            } //当前元素小于前面的元素，不是二叉排序树
            minValue = T->data;
            T = T->rchild;
        }
    }
    return true;
}

bool question8(BSTree T, int &balance, int &h)
{
    int bl = 0, br = 0, hl = 0, hr = 0;
    if (!T)
    {
        h = 0;
        balance = 1;
    } //当为空结点，树高为0，平衡因子为1
    else if (!T->lchild && !T->rchild)
    {
        h = 1;
        balance = 1;
    } //为根节点，树高为1，平衡因子为1
    else
    {
        question8(T->lchild, bl, hl);
        question8(T->rchild, br, hr);
        h = max(hl, hr) + 1;
        if (abs(hl - hr) <= 1)
        {
            balance = bl && br;
        }
        else
        {
            balance = 0;
        }
    } //否则，遍历左右子树，得到树高，左右子树高度差不大于1，表明当前结点平衡因子是1，如果子树都是平衡二叉树，则当前结点就是平衡二叉树
}