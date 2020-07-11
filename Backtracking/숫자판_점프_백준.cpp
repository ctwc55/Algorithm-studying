#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int board[5][5], ans=0;
map<string,int> chk;

void solve(int n, int m, string num, int deep){
    if(n<0||n>=5||m<0||m>=5) return;
    if(deep==5){
        if(!chk.count(num)){
            chk[num]=1;
            ans++;
        }
        return;
    }

    for(int i=0;i<4;i++) solve(n+dx[i],m+dy[i],num+to_string(board[n+dx[i]][m+dy[i]]),deep+1);

    return;
}

int main()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d", &board[i][j]);
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            solve(i,j,to_string(board[i][j]),0);
        }
    }

    printf("%d\n", ans);
}
