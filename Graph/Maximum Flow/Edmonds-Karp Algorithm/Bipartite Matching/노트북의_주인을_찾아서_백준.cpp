#include <bits/stdc++.h>
#define MAXN 105
#define INF 1000000000

using namespace std;

int N, M, c[MAXN*3][MAXN*3], f[MAXN*3][MAXN*3], bef[MAXN*3];
vector< vector<int> > laptop;
queue<int> bfs;

int solve(){
    int ans=0, x;

    while(1){
        bfs.push(0);
        for(int i=0;i<MAXN*3;i++) bef[i]=-1;
        while(!bfs.empty()){
            int node=bfs.front();
            for(int i=0;i<laptop[node].size();i++){
                int next=laptop[node][i];
                if(c[node][next]-f[node][next]>0&&bef[next]==-1){
                    bfs.push(next);
                    bef[next]=node;
                    if(next==MAXN*3-1) break;
                }
            }
            bfs.pop();
        }
        while(bfs.size()) bfs.pop();
        if(bef[MAXN*3-1]==-1) break;

        x=INF;
        for(int i=MAXN*3-1;i!=0;i=bef[i]) x=min(x,c[bef[i]][i]-f[bef[i]][i]);
        for(int i=MAXN*3-1;i!=0;i=bef[i]){
            f[bef[i]][i]+=x;
            f[i][bef[i]]-=x;
        }

        ans+=x;
    }

    return ans;
}

int main()
{
    int a, b;

    scanf("%d %d", &N, &M);
    laptop.resize(MAXN*3);
    for(int i=1;i<=N;i++){
        laptop[0].push_back(i);
        laptop[i].push_back(0);
        laptop[i+MAXN].push_back(MAXN*3-1);
        laptop[MAXN*3-1].push_back(i+MAXN);
        c[0][i]=1;
        c[i+MAXN][MAXN*3-1]=1;
    }
    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);

        laptop[a].push_back(b+MAXN);
        laptop[b+MAXN].push_back(a);
        c[a][b+MAXN]=1;
    }

    printf("%d\n", solve());
}
