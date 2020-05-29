#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int N, arr[100];
long long int memo[100][21];

long long int solve(int num, int idx){
  if(num<0||num>20) return 0;
  if(memo[idx][num]) return memo[idx][num];
  if(idx==N-1){
    if(num==arr[idx]) return 1;
    return 0;
  }
  
  memo[idx][num]+=solve(num+arr[idx],idx+1);
  memo[idx][num]+=solve(num-arr[idx],idx+1);
  
  return memo[idx][num];
}

int main()
{
  scanf("%d", &N);
  for(int i=0;i<N;i++) scanf("%d", &arr[i]);
  
  printf("%lld\n", solve(arr[0],1));
}
