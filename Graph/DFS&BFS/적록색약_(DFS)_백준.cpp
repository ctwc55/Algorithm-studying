#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int N, visit[MAXN+5][MAXN+5][2];
char screen[MAXN+5][MAXN+5];

void dfs(int x, int y, char dist, int chk){
    if(x<0||x>=N||y<0||y>=N) return;
    if(visit[x][y][chk]) return;
    if(screen[x][y]!=dist) return;

    visit[x][y][chk]=1;
    for(int i=0;i<4;i++){
        dfs(x+dx[i],y+dy[i],dist,chk);
    }
}

pair<int,int> solve(){
    int normal=0, rge=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j][0]){
                dfs(i,j,screen[i][j],0);
                normal++;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(screen[i][j]=='R') screen[i][j]='G';
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j][1]){
                dfs(i,j,screen[i][j],1);
                rge++;
            }
        }
    }

    return make_pair(normal,rge);
}

int main()
{
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        getchar();
        for(int j=0;j<N;j++){
            scanf("%c", &screen[i][j]);
        }
    }

    pair<int,int> ans=solve();

    printf("%d %d\n", ans.first, ans.second);
}
