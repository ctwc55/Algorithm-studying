#include <bits/stdc++.h>
#define MAXN 10000000000

using namespace std;

int k, chk[10];
long long int ans_max=-MAXN, ans_min=MAXN;
string str;
char str_num[15], str_max[15], str_min[15];

void solve(int a, long long int num, int len){
  if(chk[a]==1) return;
  str_num[len-1]='0'+a;
  if(len==k+1){
    if(ans_max<num){
      ans_max=num;
      strcpy(str_max,str_num);
    }
    if(ans_min>num){
      ans_min=num;
      strcpy(str_min,str_num);
    }
    str_num[len-1]='\0';
    return;
  }
  chk[a]=1;
  if(str[len*2-2]=='<'){
    for(int i=a+1;i<10;i++){
      solve(i,num*10LL+i,len+1);
    }  
  }
  else if(str[len*2-2]=='>'){
    for(int i=0;i<a;i++){
      solve(i,num*10LL+i,len+1);
    }
  } 
  chk[a]=0;
  str_num[len-1]='\0';
  return;
}

int main()
{
  scanf("%d", &k);
  getchar();
  getline(cin,str);
  for(int i=0;i<10;i++) solve(i,i,1);
  
  printf("%s\n%s", str_max, str_min);
}
