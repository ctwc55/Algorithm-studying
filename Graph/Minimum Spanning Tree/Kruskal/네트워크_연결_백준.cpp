#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

typedef struct{
    int x, y, cost;
} WIRE;

int graph[1001][1001];
int n, m, parent[1001];
WIRE lan[100001];

bool cmp(WIRE a, WIRE b){
    if(a.cost<b.cost) return true;
    else return false;
}

int findRoot(int x){
    int p;

    if(x==parent[x]) return x;
    p=findRoot(parent[x]);
    parent[x]=p;
    return p;
}

bool unionRoot(int x, int y){
    x=findRoot(x);
    y=findRoot(y);
    if(x!=y){
        parent[y]=x;
        return true;
    }
    return false;
}

int main()
{
    int a, b, ans=0;

    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++) scanf("%d %d %d", &lan[i].x, &lan[i].y, &lan[i].cost);

    sort(lan,lan+m,cmp);

    for(int i=0;i<=n;i++) parent[i]=i;

    for(int i=0;i<m;i++){
        if(graph[lan[i].x][lan[i].y]==1) continue;

        if(unionRoot(lan[i].x,lan[i].y)){
            graph[lan[i].x][lan[i].y]=1;
            graph[lan[i].y][lan[i].x]=1;
            ans+=lan[i].cost;
        }
    }

    printf("%d\n", ans);
}
