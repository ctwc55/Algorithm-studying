#include <bits/stdc++.h>
#define MAXN 500000

using namespace std;

int N, M, arr[MAXN], card, ans[MAXN];

int main()
{
  scanf("%d", &N);
  for(int i=0;i<N;i++) scanf("%d", &arr[i]);
  sort(arr,arr+N);
  
  scanf("%d", &M);
  for(int i=0;i<M;i++){
    scanf("%d", &card);
    ans[i]=(upper_bound(arr,arr+N,card)-arr)-(lower_bound(arr,arr+N,card)-arr);
  }
  
  for(int i=0;i<M;i++) printf("%d ", ans[i]);
}
