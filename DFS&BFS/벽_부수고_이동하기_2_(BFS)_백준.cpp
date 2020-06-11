#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

typedef struct{
  int x, y, dist, wall_cnt=0;
} INFO;

int N, M, K, arr[MAXN][MAXN], chk[MAXN][MAXN][11];
queue<INFO> q;

bool IdxChk(INFO a, int i){
  if(a.x+dx[i]>=0&&a.x+dx[i]<N&&a.y+dy[i]>=0&&a.y+dy[i]<M) return true;
  return false;
}

int solve(){
  q.push({0,0,1,0});
  while(!q.empty()){
    if(q.front().x==N-1&&q.front().y==M-1) return q.front().dist;
    for(int i=0;i<4;i++){
      if(IdxChk(q.front(),i)&&!chk[q.front().x+dx[i]][q.front().y+dy[i]][q.front().wall_cnt]){
        if(arr[q.front().x+dx[i]][q.front().y+dy[i]]==0) q.push({q.front().x+dx[i],q.front().y+dy[i],q.front().dist+1,q.front().wall_cnt});
        else{
          if(q.front().wall_cnt<K) q.push({q.front().x+dx[i],q.front().y+dy[i],q.front().dist+1,q.front().wall_cnt+1});
        }
        chk[q.front().x+dx[i]][q.front().y+dy[i]][q.front().wall_cnt]=1;
      }  
    }
    q.pop();
  }
  
  return -1;
}

int main()
{
  scanf("%d %d %d", &N, &M, &K);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++) scanf("%1d", &arr[i][j]);
  }
  
  printf("%d\n", solve());
}
