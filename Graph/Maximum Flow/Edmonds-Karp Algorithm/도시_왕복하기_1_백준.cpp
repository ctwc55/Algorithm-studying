#include <bits/stdc++.h>
#define MAXN 405
#define INF 1000000000

using namespace std;

int N, P, c[MAXN][MAXN], f[MAXN][MAXN], bef[MAXN];
vector< vector<int> > road;
queue<int> bfs;

int solve(){
    int ans=0, x;

    while(1){
        bfs.push(1);
        for(int i=1;i<=N;i++) bef[i]=-1;
        while(!bfs.empty()){
            int node=bfs.front();
            for(int i=0;i<road[node].size();i++){
                int next=road[node][i];
                if(c[node][next]-f[node][next]>0&&bef[next]==-1){
                    bfs.push(next);
                    bef[next]=node;
                    if(next==2) break;
                }
            }
            bfs.pop();
        }
        while(bfs.size()) bfs.pop();
        if(bef[2]==-1) break;

        x=INF;
        for(int i=2;i!=1;i=bef[i]) x=min(x,c[bef[i]][i]-f[bef[i]][i]);
        for(int i=2;i!=1;i=bef[i]){
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

    scanf("%d %d", &N, &P);
    road.resize(MAXN+1);
    for(int i=0;i<P;i++){
        scanf("%d %d", &a, &b);

        road[a].push_back(b);
        road[b].push_back(a);
        c[a][b]=1;
    }

    printf("%d\n", solve());
}
