#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int N, M;
int seq[8];

void solve(int num, int seqlen){
  if(seqlen==M){
    for(int i=0;i<seqlen;i++) printf("%d ", seq[i]);
    printf("\n");
    return;
  }
  
  for(int i=num;i<=N;i++){
    seq[seqlen]=i;
    solve(i,seqlen+1);
  }
  
  return;
}

int main()
{
  scanf("%d %d", &N, &M);
  
  for(int i=1;i<=N;i++){
    seq[0]=i;
    solve(i,1);
  }
}
