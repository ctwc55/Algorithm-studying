#include <bits/stdc++.h>
#define MAXN 100000
#define MAXM 1000000

using namespace std;

typedef struct{
    int a, b, c;
} INFO;

vector<int> parent;
int N, M;
INFO edge[MAXM];

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

int solve(){
    int ans=0, cutter;

    sort(edge,edge+M,cmp);

    for(int i=0;i<N;i++) parent[i]=i;

    for(int i=0;i<M;i++){
        if(unionRoot(edge[i].a,edge[i].b)){
            ans+=edge[i].c;
            cutter=edge[i].c;
        }
    }

    return ans-cutter;
}

int main()
{
    scanf("%d %d", &N, &M);
    parent.resize(N);
    for(int i=0;i<M;i++) scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].c);

    printf("%d\n", solve());
}
