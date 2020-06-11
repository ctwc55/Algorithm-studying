#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int dhx[8]={-2,-1,1,2,2,1,-1,-2};
int dhy[8]={1,2,2,1,-1,-2,-2,-1};

typedef struct{
  int x, y, horse, trial;
} INFO;

int K, W, H, arr[200][200], chk[200][200][31];
queue<INFO> q;

bool IdxChk1(INFO a, int i){
  if(a.x+dx[i]>=0&&a.x+dx[i]<H&&a.y+dy[i]>=0&&a.y+dy[i]<W) return true;
  return false;
}

bool IdxChk2(INFO a, int i){
  if(a.x+dhx[i]>=0&&a.x+dhx[i]<H&&a.y+dhy[i]>=0&&a.y+dhy[i]<W) return true;
  return false;
}

int solve()
{
  q.push({0,0,0,0});
  while(!q.empty()){
    if(q.front().x==H-1&&q.front().y==W-1) return q.front().trial;
    
    for(int i=0;i<4;i++){
      if(IdxChk1(q.front(),i)){
        if(arr[q.front().x+dx[i]][q.front().y+dy[i]]!=1&&!chk[q.front().x+dx[i]][q.front().y+dy[i]][q.front().horse]){
          q.push({q.front().x+dx[i],q.front().y+dy[i],q.front().horse,q.front().trial+1});
          chk[q.front().x+dx[i]][q.front().y+dy[i]][q.front().horse]=1;
        }
      }
    }
    for(int i=0;i<8;i++){
      if(IdxChk2(q.front(),i)){
        if(arr[q.front().x+dhx[i]][q.front().y+dhy[i]]!=1&&!chk[q.front().x+dhx[i]][q.front().y+dhy[i]][q.front().horse+1]){
          if(q.front().horse<K){
           q.push({q.front().x+dhx[i],q.front().y+dhy[i],q.front().horse+1,q.front().trial+1});
           chk[q.front().x+dhx[i]][q.front().y+dhy[i]][q.front().horse+1]=1;
          }
        }
      }
    }
    q.pop();
  }
  
  return -1;
}

int main()
{
  scanf("%d", &K);
  scanf("%d %d", &W, &H);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++) scanf("%d", &arr[i][j]);
  }
  
  printf("%d\n", solve());
}
