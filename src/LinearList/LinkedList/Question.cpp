#include "LinkedList.h"
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <cstring>

void question1(LinkList L, int x)
{
    if (!L)
    {
        printf("List is empty\n");
        return;
    }
    LNode *p;
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        question1(L, x);
    }
    else
    {
        question1(L->next, x);
    }
}

void question2(LinkList L, int x)
{
    if (IsEmpty(L))
    {
        return;
    }
    LNode *p = L->next, *prev = L, *q; //定义prev指向前一个结点
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            prev->next = p; //将前一个结点的后继指针指向当前结点的后继
            free(q);
        }
        else
        {
            prev = p;
            p = p->next;
        } // else
    }     // while
}

void question3(LinkList L)
{
    if (IsEmpty(L))
    {
        return;
    }
    if (L->next != NULL)
    {
        question3(L->next);
    }
    else
    {
        printf("%d ,", L->data);
    }
}

void question4(LinkList L)
{
    if (IsEmpty(L))
    {
        return;
    }
    LNode *p = L->next, *q = p, *prev = L;
    //将最小值设置初值为第一个结点，从第二个结点开始扫描
    while (p->next != NULL)
    {
        if (p->next->data < q->data)
        {
            prev = p;
            q = p->next;
        } //当下一个结点的值小于最小值时，更新最小值和最小结点及其前驱结点
        p = p->next;
    }
    //删除最小结点
    prev->next = q->next;
    free(q);
    return;
}

void question51(LinkList L)
{
    if (IsEmpty(L))
    {
        return;
    }
    LNode *p = L->next, *q;
    while (p != NULL)
    {
        q = p->next; // q指向后续结点，暂存
        p->next = L->next;
        L->next = p; //头插法将后续结点插入到前面
        p = q;       // p指向原链表的后续结点
    }
}

void question52(LinkList L)
{
    if (IsEmpty(L))
    {
        return;
    }
    LNode *p = L->next, *q, *prev = NULL;
    // prev保存已经逆置的结点序列，p指向还未逆置的结点序列
    while (p != NULL)
    {
        q = p->next;    //暂存后续结点
        p->next = prev; //当前结点指向前一结点
        prev = p;       // p加入已经逆置的结点序列
        p = q;          // p指向q
    }
    L->next = prev; //最后结束时，p、q都指向NULL，prev指向最后一个结点
}

void question6(LinkList L)
{
    if (IsEmpty(L))
    {
        return;
    }
    LNode *p = L->next, *q = p->next, *prev;
    p->next = NULL;
    p = q;
    while (p != NULL)
    {
        q = p->next;
        prev = L;
        while (prev->next != NULL && prev->next->data < p->data)
        {
            prev = prev->next;
        } //找到已经排序的链表中第一个比p大的结点，将p插入到该结点的前方
        p->next = prev->next;
        prev->next = p;
        p = q; //继续遍历后续结点
    }
}

void question7(LinkList L, int s, int t)
{
    if (IsEmpty(L))
    {
        return;
    }

    LNode *p = L->next, *prev = L, *q;
    while (p != NULL)
    {
        if (p->data > s && p->data < t)
        {
            q = p;
            p = p->next; //将p指向下一结点
            prev->next = p;
            free(q);
        } //删除当前结点，并将p指向下一个结点
        else
        {
            prev = p;
            p = p->next;
        } //继续遍历后续结点
    }
}

LinkList question8(LinkList L1, LinkList L2)
{
    int l1 = GetLength(L1), l2 = GetLength(L2), dist;
    LNode *shorter, *longer;
    if (l1 > l2)
    {
        shorter = L2;
        longer = L1;
        dist = l1 - l2;
    }
    else
    {
        shorter = L1;
        longer = L2;
        dist = l2 - l1;
    }
    while (dist--)
    {
        longer = longer->next;
    } //将长的链表缩短为与短链表长度相同
    while (longer)
    {
        if (equal(shorter, longer))
        {
            return longer;
        } //第一个相等结点即为公共结点
        else
        {
            longer = longer->next;
            shorter = shorter->next;
        }
    }
    return NULL; //无公共结点
}

void question9(LinkList L)
{
    question6(L);
    LNode *p = L->next, *q;
    while (p)
    {
        q = p;
        printf("%d ", p->data);
        p = p->next;
        free(q);
    }
}

void question10(LinkList L, LinkList L1, LinkList L2)
{
    int i = 1;
    LNode *p = L->next, *q = L1, *r = L2, *s;
    while (p)
    {
        s = p->next;
        p->next = NULL;
        if (i % 2 == 1)
        {
            //奇数放入L1
            q->next = p;
            q = p;
        }
        else
        {
            //偶数放入L2
            r->next = p;
            r = p;
        }      //放入后指针后移
        p = s; // p指向原链表的后续结点
        ++i;
    }
}

void question11(LinkList hc)
{
    LinkList A, B;
    question10(hc, A, B);
    question51(B);
}

void question12(LinkList L)
{
    if (IsEmpty(L))
    {
        return;
    }
    LNode *prev = L->next, *p = prev->next;
    while (p)
    {
        if (prev->data == p->data)
        {
            prev->next = p->next;
            p = p->next;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }
}

void question13(LinkList L1, LinkList L2)
{
    //两个链表都是递增排列，所以每次将小的结点插入到结果中
    //新的链表以递减次序排列，所以采用头插法
    if (IsEmpty(L1) || IsEmpty(L2))
        return;

    LinkList L = (LNode *)malloc(sizeof(LNode));
    if (!L)
    {
        return;
    }
    LNode *p = L1->next, *q = L2->next, *r;
    while (p && q)
    {
        if (p->data < q->data)
        {
            r = p->next;
            p->next = L->next;
            L->next = p;
            p = r;
        } // r用于暂存后续结点
        else
        {
            r = q->next;
            q->next = L->next;
            L->next = q;
            q = r;
        } //将较小的结点插入新的链表，使用头插法
    }
    while (p)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    while (q)
    {
        r = q->next;
        q->next = L->next;
        L->next = q;
        q = r;
    } //如果两个链表中有一个没有结束，则将该链表的结点头插法插入到新链表的后面
}

LinkList question14(LinkList La, LinkList Lb)
{
    //循环遍历两个链表，比较两个链表的值，小的一个后移
    if (!La || !Lb)
    {
        return NULL;
    }

    LinkList Lc = (LinkList)malloc(sizeof(LNode));
    Lc->next = NULL;
    LNode *p = La->next, *q = Lb->next;
    while (p && q)
    {
        if (p->data == q->data)
        {
            LNode *tmp = (LinkList)malloc(sizeof(LNode));
            tmp->data = p->data;
            tmp->next = Lc->next;
            Lc->next = tmp;
            p = p->next;
            q = q->next;
        } //相等时新建一个结点，将该结点使用头插法插入到Lc中
        else if (p->data < q->data)
        {
            p = p->next;
        }
        else
        {
            q = q->next;
        } //小的结点后移
    }
    return Lc;
}

void question15(LinkList La, LinkList Lb)
{
    LNode *p = La->next, *q = Lb->next, *r = La, *t;
    while (p && q)
    {
        if (p->data == q->data)
        {
            r->next = p;
            r = r->next;
            p = p->next;
            t = q;
            q = q->next;
            free(t);
        } //相等时将A中结点插入到A链表后，是否B中结点
        else if (p->data < q->data)
        {
            t = p;
            p = p->next;
            free(t);
        }
        else
        {
            t = q;
            q = q->next;
            free(t);
        } //小结点后移。释放前面结点
    }
    r->next = NULL;

    while (p)
    {
        t = p;
        p = p->next;
        free(t);
    }
    while (q)
    {
        t = q;
        q = q->next;
        free(t);
    }
}

bool question16(LinkList La, LinkList Lb)
{
    //判断子序列必须是从某一个结点开始，后续若干结点都相等，直到B链表结束
    //如果不相等，则表示上一次比较的起点不是子序列的起点
    int l1 = GetLength(La), l2 = GetLength(Lb);
    if (l1 < l2)
    {
        return false;
    } // A长度比B小时，一定不是
    LNode *p = La->next, *q = Lb->next, *prev = p;
    while (p && q)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->next;
        } //相等时同步后移，l2-1
        else
        {
            prev = prev->next;
            p = prev;
            q = Lb->next;
        } //如果不相等，则表示上一次相等的结点并不是连续子序列的起始结点，从该结点的后继结点重新开始比较
    }
    return q == NULL; //如果此时l2==0，则表明B中的元素都可以在A中找到，B是A的子集
}

void question18(LinkList L1, LinkList L2)
{
    LNode *p = L1->next, *q = L2->next;
    while (p->next != L1->next) //找到L1的尾结点
        p = p->next;
    p->next = L2->next; //将L1的尾结点链接到L2的第一个结点
    while (q->next != L2->next)
    {
        q = q->next;
    }
    q->next = L1->next; //将L2的尾结点链接到L1的第一个结点
    free(L2);
}

void question19(LinkList L)
{
    if (IsEmpty(L))
    {
        return;
    }
    LNode *p, *minprev, *minp;
    while (L->next != L) //当链表中至少一个结点时
    {
        p = L;
        minprev = p;
        minp = p->next;
        while (p->next != L)
        {
            if (p->next->data < minp->data)
            {
                //找到更小的结点
                minp = p->next;
                minprev = p;
            }
            p = p->next;
        } //循环一遍链表
        printf("%d ", minp->data);
        minprev->next = minp->next;
        free(minp); //释放最小的结点
    }
}

bool question21(LinkList L)
{
    //设置快慢两个指针，slow指针每次指向下一个元素，fast每次指向下一个元素的下一个元素，如果链表中有环，则fast指针会从后面追上slow指针，即fast==slow，无环则不会出现这种情况，且当fast==NULL或fast->next==NULL时，也可以证明无环
    if (!L)
    {
        return false;
    }
    LNode *slow = L, *fast = L->next;
    while (fast && fast->next) //当fast和fast->next!=NULL时
    {
        if (fast == slow || fast->next == slow)
        {
            return true; //当fast==slow或fast->next==slow时，代表fast已经从后面追上slow，表示此时有环
        }
        fast = fast->next->next;
        slow = slow->next; // fast一次前进两个结点，slow一次前进一个结点
    }
    return false;
    //空间复杂的是O(1)，时间复杂度是O(n)，因为如果存在环，则可以在一次遍历后的有限个结点内完成检查
}

int question22(LinkList L, int k)
{
    if (!L)
    {
        return;
    }
    //设置指针p、q，以及计数变量count，当p开始遍历时，count进行计数，当count==k时，q开始遍历，当p遍历到最后一个结点时，q正好遍历到倒数第k个结点

    int count = 0;
    LNode *p = L->next, *q = L;
    while (p)
    {
        if (++count >= k)
        {
            q = q->next;
        } //从第一个结点开始，当count==k时，表明此时q结点指向的是从p结点往后倒数k个位置的结点（注：p最后指向NULL，所以q指向的结点一定是落后p一个以上的结点，当k==1时，循环结束后，p指向NULL，q指向最后一个结点）
        p = p->next;
    }
    if (count >= k)
    {
        return 1;
    }
    return 0;
}

LNode *question23(LinkList L1, LinkList L2)
{
    int l1 = GetLength(L1), l2 = GetLength(L2); //获取L1，L2的长度
    LNode *longer, *shorter, *p, *q;
    int dist;
    if (l1 > l2)
    {
        shorter = L2;
        longer = L1;
        dist = l1 - l2;
    }
    else
    {
        shorter = L1;
        longer = L2;
        dist = l2 - l1;
    } //将短的链表赋值给shorter，长的赋值给longer，长度差值记为dist
    p = longer->next, q = shorter->next;
    while (dist--)
    {
        //将长的链表先向后移动dist的位置
        p = p->next;
    }
    //此时p，q指向的链表长度是相同的
    while (p && q && p != q)
    {
        p = p->next;
        q = q->next;
    } //两个指针同步后移
    return p;
} //时间复杂度为o(max(l1,l2))

void question24(LinkList L, int n)
{
    //以空间换时间
    int *arr = (int *)malloc(sizeof(int) * n + 1);
    memset(arr, n + 1, 0); //当arr[i]==0时，表明这个数组元素没有出现过，==1，表示曾经出现过
    LNode *p = L->next, *prev = L, *q;
    while (p)
    {
        int tmp = abs(p->data);
        if (arr[tmp] == 1)
        {
            // arr[tmp]已经被使用，则当前结点应该直接删除
            q = p;
            p = p->next;
            prev->next = p;
            free(q);
        }
        else
        {
            arr[tmp] = 1;
            p = p->next;
            prev = prev->next;
            //同步后移
        } //当该元素绝对值没有出现过时，则将该位置赋值为1
    }
} //时间复杂度O(len)，空间复杂度O(n)

void question(LinkList L)
{
    //从中间部分往后原地逆置，然后从后半部分和前半部分各取一个结点组成新链表
    LNode *p = L->next, *q = p;
    while (p)
    {
        p = p->next; // p每次前进一步
        q = q->next;
        if (p->next)
            p = p->next; // q每次前进两步
    }
    //此时p指向NULL，q指向下标为n/2的结点
    //将后半部分原地逆置
    p = q->next;
    q->next = NULL;
    LNode *r;
    while (p)
    {
        r = p->next; //暂存后续结点
        p->next = q->next;
        q->next = p; //将p插入到q结点的后面，头插法实现逆置
        p = r;
    }

    //后半段结点插入到前半段
    p = q->next;
    LNode *t = L->next;
    while (p)
    {                      //链表后半段的结点插入到指定位置
        r = p->next;       // r指向后半段的下一个结点
        p->next = t->next; //将p指向的结点插入到t结点之后
        t->next = p;
        t = p->next; // t指向前半段的下一个插入点
        p = r;
    }
} //时间复杂度为O(n)，空间复杂度为O(1)