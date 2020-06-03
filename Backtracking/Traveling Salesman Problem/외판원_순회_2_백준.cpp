#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int N, W[10][10], visit[10];
int ans=MAXN;

void solve(int city, int cost, int citynum, int start){
  if(citynum==N+1&&city==start){
    ans=min(ans,cost);
    return;
  }
  if(visit[city]) return;
  
  visit[city]=1;
  for(int i=0;i<N;i++){
    if(W[city][i]) solve(i,cost+W[city][i],citynum+1,start);
  }
  visit[city]=0;
  
  return;
}

int main()
{
  scanf("%d", &N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d", &W[i][j]);
    }
  }
  
  for(int i=0;i<N;i++) solve(i,0,1,i);
  
  printf("%d\n", ans);
}
