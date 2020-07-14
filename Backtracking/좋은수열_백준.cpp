#include <bits/stdc++.h>

using namespace std;

int N, finish=0;
string ans;

void solve(int idx){
    for(int i=1;i<=ans.size()/2;i++){
        if(ans.substr(ans.size()-i*2,i)==ans.substr(ans.size()-i,i)) return;
    }

    if(idx==N){
        finish=1;
        return;
    }

    for(int i=1;i<=3;i++){
        ans+=to_string(i);
        solve(idx+1);
        if(finish) return;
        while(ans.size()>idx) ans.pop_back();
    }
}

int main()
{
    scanf("%d", &N);
    solve(0);
    cout<<ans;
}
