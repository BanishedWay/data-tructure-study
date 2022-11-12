#include "Graph.h"
#include <cstdio>
#include <queue>
using namespace std;

bool visited[MaxVerNum];

void BFS(MGraph G, ElemType v) {
    visit(v);
    visited[v] = true; //在顶点入队前进行访问，并标记
    queue<ElemType> queue;
    queue.push(v); //当前入队
    while (!queue.empty()) {
        queue.pop(); //队头出队，将已经访问的顶点出队
        //出队的实际意义在于已经将当前顶点的所有邻接顶点入队，进而可以找到与当前结点不邻接但是连通的其他结点
        //入队的意义不是为了访问当前结点，而是为了递归找到与当前结点邻接的所有顶点，进而递归找到所有结点
        for (ElemType w = FirstNeighbor(G, v); w != -1; w = NextNeighbor(G, v, w)) {
            if (!visited[w]) {
                visit(w);
                visited[w] = true;
                queue.push(w);
            } //对于没有访问的顶点，进行访问标记，并将其入队
            //所有的结点在入队前进行访问
        }   //遍历找到v的所有的邻接顶点
    }
}

void BFSTraverse(MGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            BFS(G, i);
        }
    }
}

void DFS(MGraph G, ElemType v) {
    visit(v);
    visited[v] = true; //访问并标记已经访问的顶点
    for (ElemType w = FirstNeighbor(G, v); w != -1; w = NextNeighbor(G, v, w)) {
        if (!visited[w])
            DFS(G, w); //递归遍历一个方向上的所有未访问的顶点
    } //当一个方向上遍历完成后，依次返回到上一个存在未访问的方向的顶点
}

void DFSTraverse(MGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
}

void Dijstra(MGraph G, ElemType v) {
    bool final[MaxVerNum];    //存储顶点状态
    int dist[MaxVerNum];      //顶点当前的最短路径
    ElemType path[MaxVerNum]; //顶点的直接前驱
    for (int i = 0; i < G.vexnum; i++) {
        if (i != v && G.Edge[v][i] < 1024) {
            dist[i] = G.Edge[v][i];
            final[i] = false;
            path[i] = v;
        } else {
            final[i] = false;
            dist[i] = 1024;
            path[i] = -1;
        } //当顶点与源点邻接，则设置权值及最短路径
    }   //初始化数组

    final[v] = true;
    dist[v] = 0;
    path[v] = -1; //初始化源点

    for (ElemType i = 1; i < G.vexnum; i++) {
        //遍历n-1次
        int minValue = 1024;
        int minIndex = -1;

        for (int j = 1; j < G.vexnum; j++) {
            if (final[j] == false && dist[j] < minValue) {
                minValue = dist[j];
                minIndex = j;
            }
        } //循环找到当前顶点中路径长度最短的顶点

        final[minIndex] = true;
        path[minIndex] = i;
        //最近的顶点表明已经找到最短路径

        for (int k = 1; k < G.vexnum; k++) {
            if (final[k] == false && dist[k] > dist[minIndex] + G.Edge[minIndex][k]) {
                dist[k] = dist[minIndex] + G.Edge[minIndex][k];
                path[k] = minIndex;
            }
        } //循环更新的dist值和path
    }
}
