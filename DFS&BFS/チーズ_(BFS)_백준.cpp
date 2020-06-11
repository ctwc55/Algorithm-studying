#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

typedef struct{
  int x, y, dist;
} INFO;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int H, W, N, chk[1000][1000];
char town[1005][1005];
queue<INFO> q;

int solve(){
  int ans=0, stop=0;
  INFO tmp;
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(town[i][j]=='S'){
        q.push({i,j,0});
        chk[i][j]=1;
        stop=1;
        break;
      }
    }
    if(stop==1) break;
  }
  
  for(int i=1;i<=N;i++){
    while(!q.empty()){
      if(town[q.front().x][q.front().y]-'0'==i){
        ans+=q.front().dist;
        tmp.x=q.front().x;
        tmp.y=q.front().y;
        tmp.dist=0;
      }
      for(int j=0;j<4;j++){
        if(q.front().x+dx[j]>=0&&q.front().x+dx[j]<H&&q.front().y+dy[j]>=0&&q.front().y+dy[j]<W){
          if(town[q.front().x+dx[j]][q.front().y+dy[j]]!='X'&&!chk[q.front().x+dx[j]][q.front().y+dy[j]]){
            q.push({q.front().x+dx[j],q.front().y+dy[j],q.front().dist+1});
            chk[q.front().x+dx[j]][q.front().y+dy[j]]=1;
          }
        }
      }
      q.pop();
    }
    
    q.push(tmp);
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++) chk[i][j]=0;
    }
  }
  
  return ans;
}

int main()
{
  scanf("%d %d %d", &H, &W, &N);
  for(int i=0;i<H;i++){
    scanf("%s", town[i]);
  }
  
  printf("%d\n", solve());
}
