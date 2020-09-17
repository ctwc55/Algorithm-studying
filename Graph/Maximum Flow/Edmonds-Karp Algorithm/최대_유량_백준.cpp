#include <bits/stdc++.h>
#define MAXN 52
#define INF 1000000000

using namespace std;

int N, c[MAXN][MAXN], f[MAXN][MAXN], bef[MAXN];
vector< vector<int> > pipe;
queue<int> bfs;

int solve(){
    int ans=0, x;

    while(1){
        bfs.push(0);
        for(int i=0;i<MAXN;i++) bef[i]=-1;
        while(!bfs.empty()){
            int node=bfs.front();
            for(int i=0;i<pipe[node].size();i++){
                int next=pipe[node][i];
                if(c[node][next]-f[node][next]>0&&bef[next]==-1){
                    bfs.push(next);
                    bef[next]=node;
                    if(next==25) break;
                }
            }
            bfs.pop();
        }
        while(bfs.size()) bfs.pop();
        if(bef[25]==-1) break;

        x=INF;
        for(int i=25;i!=0;i=bef[i]) x=min(x,c[bef[i]][i]-f[bef[i]][i]);
        for(int i=25;i!=0;i=bef[i]){
            f[bef[i]][i]+=x;
            f[i][bef[i]]-=x;
        }

        ans+=x;
    }

    return ans;
}

int main()
{
    int cost, u, v;
    char a, b;

    scanf("%d", &N);
    pipe.resize(MAXN);
    for(int i=0;i<N;i++){
        getchar();
        scanf("%c %c %d", &a, &b, &cost);

        if(a<='Z') u=a-'A';
        else u=a-'a'+26;
        if(b<='Z') v=b-'A';
        else v=b-'a'+26;
        pipe[u].push_back(v);
        pipe[v].push_back(u);
        c[u][v]+=cost;
        c[v][u]+=cost;
    }

    printf("%d\n", solve());
}
