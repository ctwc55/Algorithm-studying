#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int segtodec(char seg[]){
  if(!strcmp(seg,"0111111")) return 0;
  else if(!strcmp(seg,"0001010")) return 1;
  else if(!strcmp(seg,"1011101")) return 2;
  else if(!strcmp(seg,"1001111")) return 3;
  else if(!strcmp(seg,"1101010")) return 4;
  else if(!strcmp(seg,"1100111")) return 5;
  else if(!strcmp(seg,"1110111")) return 6;
  else if(!strcmp(seg,"0001011")) return 7;
  else if(!strcmp(seg,"1111111")) return 8;
  else if(!strcmp(seg,"1101011")) return 9;
}

string dectoseg(int dec){
  if(dec==0) return "0111111";
  else if(dec==1) return "0001010";
  else if(dec==2) return "1011101";
  else if(dec==3) return "1001111";
  else if(dec==4) return "1101010";
  else if(dec==5) return "1100111";
  else if(dec==6) return "1110111";
  else if(dec==7) return "0001011";
  else if(dec==8) return "1111111";
  else if(dec==9) return "1101011";
}

int sub7seg(string str){
  stack<int> s;
  char seg[10]={};
  int index=2, a=0, b=0, code;
  
  while(1){
    code=(str[index-2]-'0')*100+(str[index-1]-'0')*10+str[index]-'0';
    while(code>0){
      s.push(code%2);
      code/=2;
    }
    while(s.size()<7) s.push(0);
    for(int i=0;i<7;i++){
      seg[i]='0'+s.top();
      s.pop();
    }
    a*=10;
    a+=segtodec(seg);
    
    if(str[index+1]=='+') break;
    index+=3;
  }
  
  index+=4;
  while(1){
    code=(str[index-2]-'0')*100+(str[index-1]-'0')*10+str[index]-'0';
    while(code>0){
      s.push(code%2);
      code/=2;
    }
    while(s.size()<7) s.push(0);
    for(int i=0;i<7;i++){
      seg[i]='0'+s.top();
      s.pop();
    }
    b*=10;
    b+=segtodec(seg);
    
    if(str[index+1]=='=') break;
    index+=3;
  }
  
  return a+b;
}

void dectocode(int dec){
  stack<int> complete_code;
  string bin;
  int code, tmp, chk;
  
  while(dec>0){
    bin=dectoseg(dec%10);
    tmp=1;
    code=0;
    for(int i=6;i>=0;i--){
      code+=(bin[i]-'0')*tmp;
      tmp*=2;
    }
    
    if(code<100) chk=1;
    while(code>0){
      complete_code.push(code%10);
      code/=10;
    }
    if(chk==1){
      complete_code.push(0);
      chk=0;
    }
    
    dec/=10;
  }
  
  while(!complete_code.empty()){
    printf("%d",complete_code.top());
    complete_code.pop();
  }
  
  return;
}

int main()
{
  int sum;
  string input(" ");
  
  while(1){
    getline(cin,input);
    if(!input.compare("BYE")) break;
        
    sum=sub7seg(input);
    
    cout<<input;
    dectocode(sum);
    printf("\n");  
  }
}
