#include <bits/stdc++.h>

using namespace std;

string s;

string solve(){
    int fc=0;
    stack<int> engine;

    int idx=0;
    while(idx<s.size()){
        if(fc==1&&s[idx]=='0'){
            idx++;
            continue;
        }
        else if(fc==1&&s[idx]=='1'){
            if(idx==s.size()-1) engine.pop();
            else fc=2;
            idx++;
            continue;
        }
        else if(fc==2&&s[idx]=='1'){
            if(idx==s.size()-1) engine.pop();
            idx++;
            continue;
        }
        else if(fc==2&&s[idx]=='0'){
            engine.pop();
            fc=0;
            if(idx<s.size()-1&&s[idx-2]=='1'&&s[idx+1]=='0')idx--;
        }

        if(s.size()-idx+1>2&&s.compare(idx,3,"100")==0){
            fc=1;
            engine.push(100);
            idx+=3;
        }
        else if(s.size()-idx+1>1&&s.compare(idx,2,"01")==0){
            idx+=2;
        }
        else{
            engine.push(0);
            idx++;
        }
    }

    if(engine.empty()) return "SUBMARINE";
    return "NOISE";
}

int main()
{
    cin>>s;

    cout<<solve()<<"\n";
}
