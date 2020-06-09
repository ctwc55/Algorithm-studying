#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int N, arr[MAXN];
vector<int> memo;

int solve(){
  for(int i=0;i<N;i++){
    if(memo.empty()) memo.push_back(arr[i]);
    else if(memo.back()<arr[i]) memo.push_back(arr[i]);
    else memo[lower_bound(memo.begin(),memo.end(),arr[i])-memo.begin()]=arr[i];
  }
  
  return memo.size();
}

int main()
{
  scanf("%d", &N);
  for(int i=0;i<N;i++) scanf("%d", &arr[i]);
  
  printf("%d\n", N-solve());
}
