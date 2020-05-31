#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int n, m, arr[1001][1001];
int memo[1001][1001], ans=0;

int main()
{
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      scanf("%1d", &arr[i][j]);
    }
  }
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(arr[i][j]==1){
        if(memo[i-1][j-1]<=memo[i-1][j]&&memo[i-1][j-1]<=memo[i][j-1]){
          memo[i][j]=memo[i-1][j-1]+1;  
        }
        else memo[i][j]=min(memo[i-1][j],memo[i][j-1])+1;
        ans=max(ans,memo[i][j]);
      }
    }
  }
  
  printf("%d\n", ans*ans);
}
