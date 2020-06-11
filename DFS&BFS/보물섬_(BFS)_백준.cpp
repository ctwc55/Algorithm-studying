#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

typedef struct{
  int x, y, dist;
} INFO;

int H, W, chk[50][50];
char treasure[55][55];
queue<INFO> q;

bool IdxChk(INFO a, int i){
  if(a.x+dx[i]>=0&&a.x+dx[i]<H&&a.y+dy[i]>=0&&a.y+dy[i]<W) return true;
  return false;
}

bool VisitChk(INFO a, int i){
  if(!chk[a.x+dx[i]][a.y+dy[i]]) return true;
  return false;
}

int bfs(int i, int j){
  int tmp=-MAXN;
  
  while(!q.empty()) q.pop();
  for(int ci=0;ci<H;ci++){
    for(int cj=0;cj<W;cj++) chk[ci][cj]=0;
  }
  
  q.push({i,j,0});
  chk[i][j]=1;
  while(!q.empty()){
    for(int k=0;k<4;k++){
      if(IdxChk(q.front(),k)&&VisitChk(q.front(),k)&&treasure[q.front().x+dx[k]][q.front().y+dy[k]]=='L'){
        q.push({q.front().x+dx[k],q.front().y+dy[k],q.front().dist+1});
        chk[q.front().x+dx[k]][q.front().y+dy[k]]=1;
        tmp=max(tmp,q.front().dist+1);
      }
    }
    q.pop();
  }
  
  return tmp;
}

int solve(){
  int ans=-MAXN;
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(treasure[i][j]=='L') ans=max(ans,bfs(i,j));
    }
  }
  
  return ans;
}

int main()
{
  scanf("%d %d", &H, &W);
  for(int i=0;i<H;i++) scanf("%s", treasure[i]);
  
  printf("%d\n", solve());
}
