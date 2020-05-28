#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int N, M;
int nums[8], seq[8];

void solve(int idx, int seqlen){
  if(seqlen==M){
    for(int i=0;i<seqlen;i++) printf("%d ", seq[i]);
    printf("\n");
    return;
  }
  
  for(int i=idx;i<N;i++){
    seq[seqlen]=nums[i];
    solve(i,seqlen+1);
  }
  
  return;
}

int main()
{
  scanf("%d %d", &N, &M);
  for(int i=0;i<N;i++) scanf("%d", &nums[i]);
  
  sort(nums,nums+N);
  
  for(int i=0;i<N;i++){
    seq[0]=nums[i];
    solve(i,1);
  }
}
