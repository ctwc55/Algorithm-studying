#include <bits/stdc++.h>
#define MAXN 500

using namespace std;

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int n, forest[MAXN][MAXN], d[MAXN][MAXN];

int dfs(int x, int y, int s){
    if(x<0||x>=n||y<0||y>=n) return 0;
    if(forest[x][y]<=s) return 0;
    if(d[x][y]!=-1) return d[x][y];

    d[x][y]=1;
    int cmp=0;
    for(int i=0;i<4;i++){
        cmp=max(cmp,dfs(x+dx[i],y+dy[i],forest[x][y]));
    }
    d[x][y]+=cmp;

    return d[x][y];
}

int solve(){
    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=-1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,dfs(i,j,0));
        }
    }

    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &forest[i][j]);
        }
    }

    printf("%d\n", solve());
}
