#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

typedef struct{
    int a, b, c;
} INFO;

vector<int> graph[10001];
int parent[10001];
INFO edge[100000];

bool cmp(INFO a, INFO b){
    if(a.c<b.c) return true;
    return false;
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
    int v, e, ans=0;
    bool pass;

    scanf("%d %d", &v, &e);

    for(int i=0;i<e;i++) scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].c);

    sort(edge,edge+e,cmp);

    for(int i=0;i<=v;i++) parent[i]=i;

    for(int i=0;i<e;i++){
        pass=false;
        for(int j=0;j<graph[edge[i].a].size();j++){
            if(graph[edge[i].a][j]==edge[i].b){
                pass=true;
                break;
            }
        }
        if(pass) continue;

        if(unionRoot(edge[i].a,edge[i].b)){
            graph[edge[i].a].push_back(edge[i].b);
            graph[edge[i].b].push_back(edge[i].a);
            ans+=edge[i].c;
        }
    }

    printf("%d\n", ans);
}
