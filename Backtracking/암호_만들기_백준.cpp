#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

vector<char> str;
int L, C, v_chk, c_chk;
int keys[15];

void FindKey(int keynum, int keylen){
  if(keylen==L){
    if(v_chk>=1&&c_chk>=2){
      for(int i=0;i<L;i++) cout<<str[i];
      printf("\n");
    }
    return;
  }
  for(int i=keynum+1;i<C;i++){
    if(keys[i]=='a'||keys[i]=='e'||keys[i]=='i'||keys[i]=='o'||keys[i]=='u'){
      v_chk++;
      str.push_back(keys[i]);
      FindKey(i,keylen+1);
      str.pop_back();
      v_chk--;
    }         
    else{
      c_chk++;
      str.push_back(keys[i]);
      FindKey(i,keylen+1);
      str.pop_back();
      c_chk--;
    }
  }
  
  return;
}

int main()
{
  scanf("%d %d", &L, &C);
  getchar();
  for(int i=0;i<C;i++){
    scanf("%c", &keys[i]);
    getchar();
  }
  sort(keys,keys+C);
  
  for(int i=0;i<C-L+1;i++){
    if(keys[i]=='a'||keys[i]=='e'||keys[i]=='i'||keys[i]=='o'||keys[i]=='u'){
      v_chk++;
      str.push_back(keys[i]);
      FindKey(i,1);
      str.pop_back();
      v_chk--;
    }         
    else{
      c_chk++;
      str.push_back(keys[i]);
      FindKey(i,1);
      str.pop_back();
      c_chk--;
    }
  }
}
