#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

int n;
int board[300][300];
int check[300][300];

void dfs(int x, int y){
    if(x<0||x>=n||y<0||y>=n) return;
    if(check[x][y]==1||board[x][y]==0) return;
    check[x][y]=1;
    for(int i=0;i<4;i++) dfs(x+dir[i][0],y+dir[i][1]);
    return;
}

void clearMemo(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) check[i][j]=0;
    }
    return;
}

int main()
{
    int cnt=0, ans=-MAXN;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d", &board[i][j]);
    }

    for(int k=1;k<=100;k++){
        cnt=0;
        clearMemo();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!=0&&check[i][j]==0){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        ans=max(ans,cnt);

        if(cnt<1) break;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]<=k) board[i][j]=0;
            }
        }
    }

    printf("%d\n", ans);
}
