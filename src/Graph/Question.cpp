#include "Graph.h"
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool visited[MaxVerNum];
void question2_1(MGraph G, ElemType v, int vNum, int eNum);
void visit(ElemType v)
{
}
void DFS(MGraph G, ElemType v)
{
    visit(v);
    visited[v] = true;
    for (ElemType w = FirstNeighbor(G, v); w != -1; w = NextNeighbor(G, v, w))
    {
        if (!visited[w])
            DFS(G, w);
    }
}
void DFSTraverse(MGraph G)
{
    for (ElemType v = 0; v < G.vexnum; v++)
    {
        visited[v] = false;
    }
    for (ElemType v = 0; v < G.vexnum; v++)
    {
        if (!visited[v])
            DFS(G, v);
    }
}

void BFS(MGraph G, ElemType v)
{
    visit(v);
    visited[v] = true;
    queue<ElemType> queue;
    queue.push(v);
    ElemType u;
    while (!queue.empty())
    {
        u = queue.front();
        queue.pop();
        for (ElemType w = FirstNeighbor(G, u); w != -1; w = NextNeighbor(G, u, w))
        {
            if (!visited[w])
            {
                visited[w] = true;
                visit(w);
                queue.push(w);
            }
        }
    }
}

void BFSTraverse(MGraph G)
{
    for (ElemType v = 0; v < G.vexnum; v++)
    {
        visited[v] = false;
    }
    for (ElemType v = 0; v < G.vexnum; v++)
    {
        if (!visited[v])
        {
            BFS(G, v);
        }
    }
}
void question2_1(MGraph G, ElemType v, int vNum, int eNum)
{
    visited[v] = true;
    vNum++;
    for (ElemType w = FirstNeighbor(G, v); w != -1; w = NextNeighbor(G, v, w))
    {
        eNum++;
        if (!visited[w])
        {
            question2_1(G, w, vNum, eNum);
        }
    }
}

bool question2(MGraph G)
{
    //使用深度优先算法
    //如果为树，则应该为连通图，且不存在回路，结点数为n，边数为n-1
    //深度优先每条边都会访问两次（无向图，访问v的边链表时一次，访问w的边链表一次）
    //如果经过1次访问，能访问到n个结点和n-1条边
    for (ElemType v = 0; v < G.vexnum; v++)
    {
        visited[v] = false;
    }
    int vNum = 0, eNum = 0;
    question2_1(G, 0, vNum, eNum);
    if (vNum == G.vexnum && eNum == 2 * (G.vexnum - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void question3(ALGraph G)
{
    stack<ElemType> S;
    for (ElemType i = 0; i < G.vexnum; ++i)
    {
        visited[i] = false;
    }
    S.push(0);
    visited[0] = true;
    while (!S.empty())
    {
        ElemType k = S.top();
        S.pop();
        visit(k);
        ArcNode *p = G.vertices[k].first;
        // p指向第一个边结点（保存第一条边的结点）
        while (!p)
        {
            if (!visited[p->adjvex])
            {
                visited[p->adjvex] = true;
                S.push(p->adjvex);
            }            //当该边邻接的结点未访问过时，该结点入栈
            p = p->next; //继续寻找下一个邻接的结点
        }
    } //在非递归的方式中，visit数组不再是标记是否被访问，而是标记是否曾经入栈
}

void question4_DFS(ALGraph G, int i, int j, bool &can_reach)
{
    if (i == j)
    {
        can_reach = true;
        return;
    }
    visited[i] = true;
    ArcNode *p = G.vertices[i].first;
    while (!p)
    {
        if (!visited[p->adjvex] && !can_reach)
        {
            question4_DFS(G, p->adjvex, j, can_reach);
        }
        p = p->next;
    }
}

bool question_BFS(ALGraph G, int i, int j)
{
    queue<ElemType> Q;
    Q.push(i);
    while (!Q.empty())
    {
        ElemType u = Q.front();
        Q.pop();
        visited[u] = true;
        if (u == j)
            return true;
        //当前结点是目标结点时，输出
        ArcNode *p = G.vertices[u].first;
        while (!p)
        {
            if (p->adjvex == j)
            {
                return true;
            } //如果邻接结点中有目标结点，返回
            if (!visited[p->adjvex])
            {
                Q.push(p->adjvex);
                visited[p->adjvex] = true;
                visit(p->adjvex);
            } //不存在则将邻接结点入队，
            p = p->next;
        } //循环变量当前结点的所有邻接结点
    }
    return false;
}

void print(int path[], int d)
{
    for (int i = 0; i <= d; ++i)
    {
        cout << path[i] << " ";
    }
}
void question5(ALGraph G, int i, int j, int path[], int d)
{
    // 使用深度优先遍历找到i==j的顶点
    // 使用path记录路径上的顶点
    // 当i==j时，表明找到结点，输出
    // 否则将该结点加入路径，访问结点的邻接结点
    // 如果结点的一条遍历结果都不含j，则回退到上层调用
    // 因为在上层调用中d的值还是在遍历前的值
    // 因为每一个顶点的邻接边链表是有头有尾的，所以当一个顶点所有的邻接结点被访问后，意味着该顶点的访问结束
    // 再因为访问当前结点时，当前结点的visited是==1的，上层顶点也是==1的，所以不可能从下层结点访问上层结点
    // 对邻接结点的访问是顺序的，上层顶点在一次调用中不可能重复调用同一个结点
    path[++d] = i;
    visited[i] = true;
    if (i == j)
    {
        print(path, d);
    }
    ArcNode *p = G.vertices[i].first;
    while (!p)
    {
        if (!visited[p->adjvex])
        {
            question5(G, p->adjvex, j, path, d);
        }
        p = p->next;
    }
    visited[i] = false;
    //类似加锁，当我在访问结点i及其以下结点时，不能再次访问结点i
}

void dijstra(MGraph G, ElemType v)
{
    //实现迪杰斯特拉算法求单源最短路径
    //策略是每一轮循环找到一个最短路径结点i，然后修改与该结点相连且到v的距离大于到i距离的结点
    //循环n-1次，直到将所有结点遍历一次
    bool final[MaxVerNum]; //记录结点是否已经找到最短路径
    int dist[MaxVerNum];   //记录结点当前的最短距离

    for (int i = 0; i < G.vexnum; ++i)
    {

        if (i != v && G.Edge[v][i] < 1024)
        {
            dist[i] = G.Edge[v][i];
        }
        else
        {
            dist[i] = 1024;
        }
        final[i] = false;
    } //将所有邻接与v的结点最短距离赋初值，不邻接标记为不可达

    //初始化源点，防止访问
    final[v] = true;
    dist[v] = 0;

    //循环访问找到最短路径的一个结点，该结点标记为已经找到最短路径
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (i == v)
        {
            continue;
        }
        int minIndex = -1;
        int minValue = 1024;

        for (int j = 0; j < G.vexnum; j++)
        {
            if (final[j] == false && dist[j] < minValue)
            {
                minValue = dist[j];
                minIndex = j;
            }
        } //找到当前未访问过结点中，路径最短的一个
        //因为每次找到的最短结点，可以确定该路径为最短路径
        //因为后续找到的结点的第一段路径都比当前路径更长

        final[minIndex] = true; //将该顶点标记为已找到

        for (ElemType j = 0; j < G.vexnum; ++j)
        {
            if (final[j] == false && minValue + G.Edge[minIndex][j] < dist[j])
            {
                dist[j] = minValue + G.Edge[minIndex][j];
                //更新路径的当前最短路径
            }
        }
    } //循环n-1次
} //时间复杂度为O(n^2)

void TopologivalSort(ALGraph G, int indegree[])
{
    stack<ElemType> S;
    for (int i = 0; i < G.vexnum; ++i)
    {
        //将所有入度为0的顶点入栈
        if (!indegree[i])
        {
            S.push(i);
        }
    }
    int count = 0; //记录已经输出的顶点
    int print[MaxVerNum];
    while (!S.empty())
    {
        int p = S.top();
        S.pop();
        print[count++] = p; //输出入度为0的顶点
        for (ArcNode *q = G.vertices[p].first; q; q = q->next)
        {
            if (!--indegree[q->adjvex])
            {
                S.push(q->adjvex);
            } //如果与p邻接的结点在删除p后，入度变为1，结点入栈
        }
    }
    if (count == G.vexnum)
    {
        printf("Finished");
    }
    else
    {
        printf("Error");
    } //当输出结点的数量==图的数量时，表示拓扑排序成功，否则失败
} // O(|V|+|E|)
