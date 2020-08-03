#include <bits/stdc++.h>
#define MAXN 500
#define INF 1000000000

using namespace std;

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int M, N;
int board[MAXN][MAXN], d[MAXN][MAXN];

int dfs(int x, int y, int height){
    if(x<0||x>=M||y<0||y>=N) return 0;
    if(board[x][y]>=height) return 0;
    if(!d[x][y]) return 0;
    if(d[x][y]!=-1||(x==M-1&&y==N-1)) return d[x][y];

    d[x][y]=0;
    for(int i=0;i<4;i++){
        d[x][y]+=dfs(x+dx[i],y+dy[i],board[x][y]);
    }

    return d[x][y];
}

int solve(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            d[i][j]=-1;
        }
    }
    d[M-1][N-1]=1;
    dfs(0,0,INF);

    return d[0][0];
}

int main()
{
    scanf("%d %d", &M, &N);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &board[i][j]);
        }
    }

    printf("%d\n", solve());
}
