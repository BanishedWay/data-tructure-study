#include "BiTree.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

void InitBiTree(BiTree root)
{
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = 1;
    root->lchild = NULL;
    root->rchild = NULL;
}

void visit(BiTNode *node)
{
    printf("%d ", node->data);
}

void PreOrder(BiTree T)
{
    if (!T)
    {
        return; //判断是否为空，也是递归结束条件
    }

    visit(T);            //访问根结点
    PreOrder(T->lchild); //递归遍历左子树
    PreOrder(T->rchild); //递归遍历右子树
}

void InOrder(BiTree T)
{
    if (!T)
    {
        return;
    }
    InOrder(T->lchild); //先遍历左子树
    visit(T);           //访问根结点
    InOrder(T->rchild); //最后遍历右子树
}

void PostOrder(BiTree T)
{
    if (!T)
    {
        return;
    }
    PostOrder(T->lchild); //先访问左子树
    PostOrder(T->rchild); //然后访问右子树
    visit(T);             //最后访问根结点
}

void CreateInThread(ThreadTree T)
{
    if (!T)
    {
        return;
    }
    ThreadTree prev = NULL;

    InThread(T, prev);
    prev->rchild = NULL;
    prev->rtag = 1; //将遍历的最后一个结点的右指针线索化
}

void InThread(ThreadTree &T, ThreadTree &prev)
{
    if (!T)
    {
        return;
    }
    InThread(T->lchild, prev); //线索化左子树

    if (T->lchild == NULL)
    {
        T->lchild = prev;
        T->ltag = 1;
    } //将左指针指向线索前驱
    if (prev != NULL && prev->rchild == NULL)
    {
        prev->lchild = T;
        prev->rtag = 1;
    } //将线索前驱的后继指向当前结点
    prev = T;

    //线索化右子树
    InThread(T->rchild, prev);
}

void CreatePreThread(ThreadTree T)
{
    if (!T)
    {
        return;
    }
    ThreadTree prev = NULL;
    PreThread(T, prev);
    prev->rchild = NULL;
    prev->rtag = 1;
}

void PreThread(ThreadTree &T, ThreadTree &prev)
{
    if (!T)
    {
        return;
    }
    if (T->lchild == NULL)
    {
        T->lchild = prev;
        T->ltag = 1;
    } //线索化左子树

    if (prev != NULL && prev->rchild == NULL)
    {
        prev->rchild = T;
        prev->rtag = 1;
    } //线索化前驱的右指针
    prev = T;

    if (T->ltag == 0)
    {
        PreThread(T->lchild, prev);
    } //只有根结点的左指针不是线索指针时，才会线索化左子树

    PreThread(T->rchild, prev); //线索化右子树
}

void CreatePostThread(ThreadTree T)
{
    if (!T)
    {
        return;
    }
    ThreadTree prev = NULL;
    PostThread(T, prev);
    prev->rchild = NULL;
    prev->rtag = 1;
}

void PostThread(ThreadTree &T, ThreadTree &prev)
{
    if (!T)
    {
        return;
    }

    PostThread(T->lchild, prev);
    PostThread(T->rchild, prev);

    if (T->lchild == NULL)
    {
        T->lchild = prev;
        T->ltag = 1;
    }
    if (prev != NULL && prev->rchild == NULL)
    {
        prev->rchild = T;
        prev->rtag = 1;
    }
    prev = T;
}

ThreadNode *NextThreadInNode(ThreadNode *p)
{
    if (p->rtag == 1)
    {
        return p->rchild; //存在右线索后继时，返回
    }
    else
    {
        return InFirstNode(p->rchild); //否则返回右子树的中序第一个结点
    }
}

ThreadNode *InFirstNode(ThreadNode *p)
{
    while (p->ltag == 0)
    {
        p = p->lchild;
    } //循环找到以p为根结点的子树的中序序列的第一个结点
    return p;
}

void InOrder(ThreadTree T)
{
    for (ThreadNode *p = InFirstNode(T); p; p = NextThreadInNode(p))
    {
        printf("%d ", p->data);
    }
}

ThreadNode *InLastNode(ThreadNode *p)
{
    while (p->rtag == 0)
    {
        p = p->rchild;
    } //循环找到左子树的最后一个结点
    return p;
}
ThreadNode *PrevThreadInNode(ThreadNode *p)
{
    if (p->ltag == 1)
    {
        return p->lchild;
    }
    else
    {
        return InLastNode(p->lchild);
    } //返回中序前驱
}

void InOrderReverse(ThreadTree T)
{
    for (ThreadNode *p = InLastNode(T); p; p = PrevThreadInNode(p))
    {
        printf("%d ", p->data);
    }
}

ThreadNode *PreFirstNode(ThreadNode *p)
{
    if (p->ltag == 0)
    {
        return p->lchild;
    }
    else
    {
        return p->rchild;
    } //如果有左孩子，返回左孩子，否则返回右孩子
}

ThreadNode *NextThreadPrevNode(ThreadNode *p)
{
    if (p->rtag == 1)
    {
        return p->rchild; //存在线索后继
    }
    else
    { //存在右孩子
        return PreFirstNode(p);
    }
}

ThreadNode *PostLastNode(ThreadNode *p)
{
    if (p->rtag == 0)
    {
        return p->rchild; //存在右子树则返回右孩子结点
    }
    else
    {
        return p->lchild; //否则返回左孩子结点
    }
}
ThreadNode *PrevThreadPostNode(ThreadNode *p)
{
    if (p->ltag == 1)
    {
        return p->lchild; //存在线索则返回线索前驱
    }
    else
    {
        return PostLastNode(p); //无则返回左右子树中的一个
    }
}

void PreOrderTraverse(BiTree T)
{
    if (!T)
    {
        return;
    } //空树，返回

    stack<BiTNode *> stack;
    stack.push(T);  //将根结点入栈，
    BiTNode *p = T; //定义游标
    while (p && !stack.empty())
    {
        //当前结点不为空则可以继续运行
        p = stack.top(); //弹出栈顶，表明访问当前结点
        stack.pop();
        visit(p);
        if (p->rchild)
        {
            stack.push(p->rchild);
        } //先将右子树入栈
        if (p->lchild)
        {
            stack.push(p->lchild);
        } //然后将左子树入栈
        //访问结束后，将左右孩子压入栈
    }
}

void InOrderTreverse(BiTree T)
{
    if (!T)
    {
        return;
    }

    stack<BiTNode *> stack;
    BiTNode *p = T;
    while (p || !stack.empty())
    {
        if (p != NULL)
        {
            stack.push(p);
            p = p->lchild; //第一次路过，先将当前结点压入栈，访问左子树
        }
        else
        {
            // p==NULL，表明左子树为空或者右子树为空，退栈
            p = stack.top();
            stack.pop();
            visit(p);
            //第二次路过，访问该结点，此时表明左子树和根结点已经访问完毕，前往右子树
            p = p->rchild;
        }
    }
}

void PostOrderTraverse(BiTree T)
{
    if (!T)
    {
        return;
    }

    stack<BiTNode *> stack;
    BiTNode *p = T, *prev = NULL;

    while (p || !stack.empty())
    {
        if (p != NULL)
        {
            stack.push(p);
            p = p->lchild; //第一次路过，入栈
        }                  //找到左子树最左下角结点
        else
        {
            p = stack.top();
            //当此时右孩子已经访问过或者为空时才访问当前结点
            if (p->rchild == NULL || p->rchild == prev)
            {
                p = stack.top();
                stack.pop();
                visit(p);
                prev = p; // prev指向p，表明上一个已经访问的结点，接下来就是寻找后继
                p = NULL; //在退栈时，设置为p，防止下一次循环时扫描p不为NULL，将p重复入栈
                //每一次退栈都意味着当前结点的子树都已经访问完成，需要将p置为NULL
            }
            else
            {
                p = p->rchild; //否则前往右子树
            }
        }
    }
}

BSTNode *BST_Search(BSTree T, int key)
{
    while (T && T->data != key)
    {
        if (T->data < key)
        {
            T = T->rchild;
        }
        else
        {
            T = T->lchild;
        }
    }
    return T;
}

bool BST_Insert(BSTree &T, int key)
{
    if (!T)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        return true;
    } //当为叶子结点时，插入
    else if (T->data == key)
    {
        return false;
    }
    else if (T->data > key)
    {
        return BST_Insert(T->lchild, key);
    }
    else
    {
        return BST_Insert(T->rchild, key);
    }
}
