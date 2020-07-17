#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int m, n, ans;
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
char board[105][105];

void dfs(int x, int y){
    if(x<0||x>=m||y<0||y>=n) return;
    if(board[x][y]=='#') return;
    if(board[x][y]=='@'){
        board[x][y]='#';
        for(int k=0;k<8;k++) dfs(x+dir[k][0],y+dir[k][1]);
    }
    else board[x][y]='#';
    return;
}

int main()
{
    while(1){
        scanf("%d %d", &m, &n);
        if(m==0) break;
        getchar();
        for(int i=0;i<m;i++) gets(board[i]);

        ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='@'){
                    ans++;
                    dfs(i,j);
                }
            }
        }

        printf("%d\n", ans);
    }
}
