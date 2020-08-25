#include <bits/stdc++.h>
#define INF 1000000000000

using namespace std;

long long ans=-INF;

void solve(vector<long long> num, vector<char> sym, vector<int> chk){
    if(sym.empty()){
        ans=max(ans,num[0]);

        return;
    }

    long long make;
    for(int i=0;i<num.size()-1;i++){
        if(chk[i]||i>0&&chk[i+1]) continue;

        vector<long long> num_next=num;
        vector<char> sym_next=sym;
        vector<int> chk_next=chk;

        if(sym[i]=='+') make=num[i]+num[i+1];
        else if(sym[i]=='-') make=num[i]-num[i+1];
        else make=num[i]*num[i+1];
        num_next.erase(num_next.begin()+i,num_next.begin()+i+2);
        num_next.insert(num_next.begin()+i,make);

        chk_next.erase(chk_next.begin()+i,chk_next.begin()+i+2);
        if(i>0) chk_next.insert(chk_next.begin()+i,1);
        else chk_next.insert(chk_next.begin()+i,0);

        sym_next.erase(sym_next.begin()+i);

        solve(num_next,sym_next,chk_next);
    }

    return;
}

int main()
{
    int N;
    char c;
    vector<long long> num;
    vector<char> sym;
    vector<int> chk;

    scanf("%d", &N);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%c", &c);
        if(i%2==0) num.push_back(c-'0');
        else sym.push_back(c);
    }

    chk.resize(num.size(),0);
    solve(num,sym,chk);

    printf("%d\n", ans);
}
