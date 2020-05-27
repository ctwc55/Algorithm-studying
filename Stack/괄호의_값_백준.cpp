#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

stack<char> s; 
char bracket[35];
int idx=-1, chk;

int ChkBracket(){
  for(int i=0;bracket[i]!='\0';i++){
    if(bracket[i]=='('||bracket[i]=='[') s.push(bracket[i]);
    else if(bracket[i]==')'){
      if(!s.empty()&&s.top()=='(') s.pop();
      else s.push(')'); 
    }
    else if(bracket[i]==']'){
      if(!s.empty()&&s.top()=='[') s.pop();
      else s.push(']'); 
    }
  }
  if(s.empty()) return 0;
  return 1;
}

int solve(){
  int res=1, brklen=strlen(bracket);
  
  while(1){
    idx++;
    if(idx==brklen) break;
    if(bracket[idx]=='('){
      s.push('(');
      if(res==1) res--;
      res+=2*solve();
    }
    else if(bracket[idx]==')'){
      if(!s.empty()&&s.top()=='(') s.pop();
      return res;
    }
    else if(bracket[idx]=='['){
      s.push('[');
      if(res==1) res--;
      res+=3*solve();
    }
    else if(bracket[idx]==']'){
      if(!s.empty()&&s.top()=='[') s.pop();
      return res;
    }
    else chk=1;
  }
  
  return res;
}

int main()
{
  int ans, pass=0;
  scanf("%s", bracket);
  
  pass=ChkBracket();
  if(pass==0) ans=solve();
  
  if(!s.empty()||chk==1) printf("0\n");
  else printf("%d\n", ans);
}
