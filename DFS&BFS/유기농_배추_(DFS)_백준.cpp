#include <bits/stdc++.h>
#define MAXN 50

using namespace std;

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int M, N, K;
int field[MAXN][MAXN];

void solve(int x, int y){
    if(x<0||x>=N||y<0||y>=M) return;
    if(field[x][y]==0||field[x][y]==2) return;

    field[x][y]=2;
    for(int i=0;i<4;i++) solve(x+dx[i],y+dy[i]);

    return;
}

int main()
{
    int T, X, Y, ans;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d", &M, &N, &K);
        for(int j=0;j<K;j++){
            scanf("%d %d", &X, &Y);
            field[Y][X]=1;
        }

        ans=0;
        for(int j=0;j<N;j++){
            for(int l=0;l<M;l++){
                if(field[j][l]==1){
                    solve(j,l);
                    ans++;
                }
            }
        }

        printf("%d\n", ans);

        for(int j=0;j<N;j++){
            for(int l=0;l<M;l++) field[j][l]=0;
        }
    }
}
