#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int nNode, nEdge, startNode;
int check[1001], graph[1001][1001];

queue<int> q;

int dfs(int curNode);
int bfs();

int main()
{
    int depart, arrive;
    scanf("%d %d %d", &nNode, &nEdge, &startNode);
    for(int i=1;i<=nEdge;i++){
        scanf("%d %d", &depart, &arrive);
        graph[depart][arrive]=1;
        graph[arrive][depart]=1;
    }
    dfs(startNode);
    printf("\n");
    bfs();
}

int dfs(int curNode){
    if(check[curNode]==1) return 0;

    check[curNode]=1;
    printf("%d ", curNode);
    for(int i=1;i<=nNode;i++){
        if(graph[curNode][i]==1&&check[i]==0){
            dfs(i);
        }
    }
}

int bfs(){
    for(int i=1;i<=nNode;i++){
        check[i]=0;
        if(graph[startNode][i]==1) q.push(i);
    }
    printf("%d ", startNode);
    check[startNode]=1;

    while(!q.empty()){
        if(check[q.front()]==0){
            printf("%d ", q.front());
            check[q.front()]=1;
        }
        for(int i=1;i<=nNode;i++){
            if(graph[q.front()][i]==1&&check[i]==0){
                q.push(i);
            }
        }
        q.pop();
    }
}
