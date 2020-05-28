#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int N, K, memo[201][201];

int solve(int a, int cnt){
  if(a<0) return 0;
  if(memo[a][cnt]) return memo[a][cnt];
  if(cnt==1) return 1;
  
  for(int i=0;i<=N;i++) memo[a][cnt]=(memo[a][cnt]+solve(a-i,cnt-1))%1000000000;
  
  return memo[a][cnt];
}

int main()
{
  scanf("%d %d", &N, &K);
  
  printf("%d\n", solve(N,K));
}
