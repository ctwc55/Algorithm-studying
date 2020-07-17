#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int dr[8]={-1,0,1,-1,1,-1,0,1};
int dw[8]={-1,-1,-1,0,0,1,1,1};

int N,M,K;
int board[105][105], area[105], cnt;

int dfs(int n, int m);

int main()
{
    int g=0;
    int x1,x2,y1,y2;
    scanf("%d %d %d", &N, &M, &K);
    for(int i=0;i<K;i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int x=x1;x<x2;x++){
            for(int y=y1;y<y2;y++){
                board[x][y]=1;
            }
        }
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0){
                cnt=0;
                dfs(i,j);
                area[g]=cnt;
                g++;
            }
        }
    }

    sort(area,area+g);

    printf("%d\n", g);
    for(int i=0;i<g;i++) printf("%d ", area[i]);
}

//check=2
int dfs(int n, int m){
    if(n<0||n>=M||m<0||m>=N||board[n][m]==2||board[n][m]==1) return 0;

    cnt++;
    board[n][m]=2;
    dfs(n-1,m);
    dfs(n,m-1);
    dfs(n,m+1);
    dfs(n+1,m);
}
