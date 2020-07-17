#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

int n, m;
int board[300][300];
int sub[300][300];
int check[300][300];

void dfs(int x, int y){
    if(x<0||x>=n||y<0||y>=m) return;
    if(check[x][y]==1||board[x][y]==0) return;
    check[x][y]=1;
    for(int i=0;i<4;i++) dfs(x+dir[i][0],y+dir[i][1]);
    return;
}

void clearMemo(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sub[i][j]=0;
            check[i][j]=0;
        }
    }
    return;
}

int melt(int x, int y, int deep){
    int rmv=0;
    if(x<0||x>=n||y<0||y>=m) return 0;
    if(deep==2) return 0;
    if(deep==1&&board[x][y]!=0) return 0;
    if(deep==1&&board[x][y]==0) return 1;
    for(int i=0;i<4;i++) rmv+=melt(x+dir[i][0],y+dir[i][1],deep+1);
    sub[x][y]=rmv;
    return 0;
}

int main()
{
    int year=0, cnt=0;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%d", &board[i][j]);
    }

    while(1){
        cnt=0;
        clearMemo();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!=0&&check[i][j]==0){
                    cnt++;
                    dfs(i,j);
                }
            }
        }

        if(cnt!=1) break;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!=0) melt(i,j,0);
            }
        }
        year++;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sub[i][j]>0) board[i][j]=max(0,board[i][j]-sub[i][j]);
            }
        }
    }

    if(cnt==0) printf("0\n");
    else printf("%d\n", year);
}
