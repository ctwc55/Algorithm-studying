#include <bits/stdc++.h>
#define MAXN 405
#define INF 1000000000

using namespace std;

int N, P, c[MAXN*3][MAXN*3], f[MAXN*3][MAXN*3], bef[MAXN*3];
vector< vector<int> > road;
queue<int> bfs;

int solve(){
    int ans=0, x;

    while(1){
        bfs.push(1+MAXN);
        for(int i=1;i<=MAXN*3;i++) bef[i]=-1;
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
        for(int i=2;i!=1+MAXN;i=bef[i]) x=min(x,c[bef[i]][i]-f[bef[i]][i]);
        for(int i=2;i!=1+MAXN;i=bef[i]){
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
    road.resize(MAXN*3);
    for(int i=1;i<=N;i++){
        road[i].push_back(i+MAXN);
        road[i+MAXN].push_back(i);
        c[i][i+MAXN]=1;
    }
    for(int i=0;i<P;i++){
        scanf("%d %d", &a, &b);

        road[a+MAXN].push_back(b);
        road[b].push_back(a+MAXN);
        road[b+MAXN].push_back(a);
        road[a].push_back(b+MAXN);
        c[a+MAXN][b]=1;
        c[b+MAXN][a]=1;
    }

    printf("%d\n", solve());
}
