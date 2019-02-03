#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int dr[8]={-1,0,1,-1,1,-1,0,1};
int dw[8]={-1,-1,-1,0,0,1,1,1};

stack<int> st;

int main()
{
    int cnt=0;
    string s;
    cin>>s;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            st.push(0);
        }
        else if(s[i]==')'&&s[i-1]=='('){
            cnt+=st.size()-1;
            st.pop();
        }
        else if(s[i]==')'&&s[i-1]==')'){
            cnt+=1;
            st.pop();
        }
    }
    printf("%d\n",cnt);
}
