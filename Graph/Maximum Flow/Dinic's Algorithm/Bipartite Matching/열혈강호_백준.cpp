#include <bits/stdc++.h>
#define MAXN 1000
#define MEM 2005
#define INF 1000000000

using namespace std;

int N, M, c[MEM][MEM], f[MEM][MEM], level[MEM], chk[MEM];
vector< vector<int> > work;
queue<int> bfs;

bool d_bfs(){
    for(int i=0;i<MEM;i++) level[i]=-1;
    level[0]=0;

    bfs.push(0);
    while(!bfs.empty()){
        int node=bfs.front();
        for(int i=0;i<work[node].size();i++){
            int next=work[node][i];
            if(level[next]==-1&&c[node][next]-f[node][next]>0){
                level[next]=level[node]+1;
                bfs.push(next);
            }
        }
        bfs.pop();
    }

    return level[MEM-1]!=-1;
}

int d_dfs(int node, int fin, int flow){
    if(node==fin) return flow;

    for(int &i=chk[node];i<work[node].size();i++){
        int next=work[node][i];

        if(level[next]==level[node]+1&&c[node][next]-f[node][next]>0){
            int minflow=d_dfs(next,fin,min(flow,c[node][next]-f[node][next]));

            if(minflow>0){
                f[node][next]+=minflow;
                f[next][node]-=minflow;
                return minflow;
            }
        }
    }

    return 0;
}

int solve(){
    int ans=0, x;

    while(d_bfs()){
        for(int i=0;i<MEM;i++) chk[i]=0;

        while(1){
            x=d_dfs(0,MEM-1,INF);
            if(x==0) break;

            ans+=x;
        }
    }

    return ans;
}

int main()
{
    int a, b;

    scanf("%d %d", &N, &M);
    work.resize(MEM);
    for(int i=1;i<=N;i++){
        work[0].push_back(i);
        work[i].push_back(0);
        c[0][i]=1;
    }
    for(int i=1;i<=M;i++){
        work[i+MAXN].push_back(MEM-1);
        work[MEM-1].push_back(i+MAXN);
        c[i+MAXN][MEM-1]=1;
    }
    for(int i=1;i<=N;i++){
        scanf("%d", &a);
        for(int j=0;j<a;j++){
            scanf("%d", &b);
            work[i].push_back(b+MAXN);
            work[b+MAXN].push_back(i);
            c[i][b+MAXN]=1;
        }
    }

    printf("%d\n", solve());
}
