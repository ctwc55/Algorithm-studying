#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int N, K, B, arr[100];

int main()
{
  int idx, ans=0;
  
  scanf("%d %d %d", &N, &K, &B);
  for(int i=0;i<N;i++) scanf("%d", &arr[i]);
  
  for(int i=1;i<=B+K-1;i++){
    if(i>=B) ans+=arr[(i-1)%N];
  }
  
  printf("%d\n", ans);
}
