#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

int n, m;
int input[8][8];
int board[8][8];
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

typedef struct{
    int i, x, y;
}PIVOT;

bool setBoard(PIVOT p[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j]=input[i][j];
            for(int k=0;k<3;k++){
                if(i==p[k].x&&j==p[k].y&&input[i][j]==0) board[i][j]=1;
                else if(i==p[k].x&&j==p[k].y&&input[i][j]!=0) return false;
            }
        }
    }
    return true;
}

void dfs(int x, int y){
    if(x<0||x>=n||y<0||y>=m) return;
    if(board[x][y]==1||board[x][y]==5) return;
    board[x][y]=5;
    for(int i=0;i<4;i++) dfs(x+dir[i][0],y+dir[i][1]);
}

int safeAreaCnt(){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0) cnt++;
        }
    }
    return cnt;
}

int main()
{
    PIVOT p[3];
    int ans=-MAXN;

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%d", &input[i][j]);
    }

    p[0].i=0;
    while(p[0].i<(n*m)-2){
        p[1].i=p[0].i+1;
        while(p[1].i<(n*m)-1){
            p[2].i=p[1].i+1;
            while(p[2].i<n*m){
                for(int i=0;i<3;i++){
                    p[i].x=p[i].i/m;
                    p[i].y=p[i].i%m;
                }

                if(setBoard(p)){
                    for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++){
                            if(board[i][j]==2) dfs(i,j);
                        }
                    }
                    ans=max(ans,safeAreaCnt());
                }
                p[2].i++;
            }
            p[1].i++;
        }
        p[0].i++;
    }

    printf("%d\n", ans);
}
