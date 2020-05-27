#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

pair<int,int> tree[26][26];
int chk[26];

void order(int n, int option){
  if(chk[n]==1) return;
  
  chk[n]=1;
  if(option==0) printf("%c",'A'+n);
  for(int i=0;i<26;i++) if(tree[n][i].second==1) order(i,option);
  if(option==1) printf("%c",'A'+n);
  for(int i=0;i<26;i++) if(tree[n][i].second==2) order(i,option);
  if(option==2) printf("%c",'A'+n);

  return;
}

int main()
{
  int n;
  char p, cl, cr;
  
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    getchar();
    scanf("%c %c %c",&p,&cl,&cr);
    if(cl!='.'){
      tree[p-'A'][cl-'A'].first=1;
      tree[p-'A'][cl-'A'].second=1;  
    }
    if(cr!='.'){
      tree[p-'A'][cr-'A'].first=1;
      tree[p-'A'][cr-'A'].second=2;  
    }
  }
  
  for(int i=0;i<3;i++){
    for(int j=0;j<26;j++) chk[j]=0;
    order(0,i);
    printf("\n");
  }
}
