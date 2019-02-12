#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int dr[8]={-1,0,1,-1,1,-1,0,1};
int dw[8]={-1,-1,-1,0,0,1,1,1};

stack<int> s;

int conv(char line[]){
    int make=0, start;
    if(line[6]=='-') start=7;
    else start=6;
    for(int i=start;line[i]!=' ';i++){
        make*=10;
        make+=line[i]-'0';
    }
    if(line[6]=='-') make*=-1;
    return make;
}

void s_push(int n){
    s.push(n);
    return;
}

void s_top(){
    if(s.empty()){
        printf("-1\n");
        return;
    }
    printf("%d\n",s.top());
    return;
}

void s_pop(){
    if(s.empty()) return;
    s.pop();
    return;
}

void s_size(){
    printf("%d\n",s.size());
    return;
}

void s_empty(){
    printf("%s\n",s.empty()?"true":"false");
    return;
}

int main()
{
    int n;
    char com[105]={};
    scanf("%d", &n);
    fflush(stdin);
    for(int i=1;i<=n+1;i++){
        gets(com);
        if(com[0]=='p'&&com[1]=='u') s_push(conv(com));
        else if(com[0]=='t') s_top();
        else if(com[0]=='p'&&com[1]=='o') s_pop();
        else if(com[0]=='s') s_size();
        else if(com[0]=='e') s_empty();
    }
}
