#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int N, M;
string S;

int main()
{
  int ans=0, cnt=0, i=0, chk=0;
  scanf("%d %d", &N, &M);
  cin>>S;
  
  while(i<M){
    if(chk==1){
      if(S[i-1]=='O'&&S[i]=='I'){
        if(cnt==N-1) ans++;
        else cnt++;
        i++;
      }
      else{
        chk=0;
        cnt=0;
        i--;
        continue;
      }
    }
    else if(S[i]=='I'){
      chk=1;
      i++;
    }
    i++;
  }
  
  printf("%d\n", ans);
}
