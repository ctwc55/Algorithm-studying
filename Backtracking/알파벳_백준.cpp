#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int r, c, chk[26];
char board[25][25];

int solve(int n, int m, int dist){
    int ans=-MAXN;

    if(n<0||n>=r||m<0||m>=c) return dist;
    if(chk[board[n][m]-'A']) return dist;

    chk[board[n][m]-'A']=1;
    for(int i=0;i<4;i++){
        ans=max(ans,solve(n+dx[i],m+dy[i],dist+1));
    }
    chk[board[n][m]-'A']=0;

    return ans;
}

int main()
{
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++){
        getchar();
        for(int j=0;j<c;j++){
            scanf("%c", &board[i][j]);
        }
    }

    printf("%d\n", solve(0,0,0));
}
