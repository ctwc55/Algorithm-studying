#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int n, arr[MAXN];
stack<int> s;
vector<char> ans;

int main()
{
  int arr_idx=0, num=1, minus_cnt=0;
  
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%d", &arr[i]);
  
  while(minus_cnt<n){
    if(s.empty()||s.top()<arr[arr_idx]){
      s.push(num++);
      ans.push_back('+');
    }
    else if(s.top()>arr[arr_idx]) break;
    else{
      s.pop();
      ans.push_back('-');
      minus_cnt++;
      arr_idx++;
    }
  }
  
  if(minus_cnt==n){
    for(int i=0;i<ans.size();i++) printf("%c\n", ans[i]);
  }
  else printf("NO\n");
}
