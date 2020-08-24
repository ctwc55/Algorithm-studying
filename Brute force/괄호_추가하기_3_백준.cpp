#include <bits/stdc++.h>
#define INF 1000000000000

using namespace std;

long long ans=-INF;

void solve(vector<long long> num, vector<char> sym){
    if(sym.empty()){
        ans=max(ans,num[0]);

        return;
    }

    long long make;
    for(int i=0;i<num.size()-1;i++){
        vector<long long> num_next=num;
        vector<char> sym_next=sym;

        if(sym[i]=='+') make=num[i]+num[i+1];
        else if(sym[i]=='-') make=num[i]-num[i+1];
        else make=num[i]*num[i+1];
        num_next.erase(num_next.begin()+i,num_next.begin()+i+2);
        num_next.insert(num_next.begin()+i,make);

        sym_next.erase(sym_next.begin()+i);

        solve(num_next,sym_next);
    }

    return;
}

int main()
{
    int N;
    char c;
    vector<long long> num;
    vector<char> sym;

    scanf("%d", &N);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%c", &c);
        if(i%2==0) num.push_back(c-'0');
        else sym.push_back(c);
    }

    solve(num,sym);

    printf("%d\n", ans);
}
