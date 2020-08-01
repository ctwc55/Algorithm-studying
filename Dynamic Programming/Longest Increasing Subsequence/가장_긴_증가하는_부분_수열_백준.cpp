#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> seq, d;

int solve(){
    for(int i=0;i<N;i++){
        if(d.empty()) d.push_back(seq[i]);
        else{
            if(d[d.size()-1]<seq[i]) d.push_back(seq[i]);
            else d[lower_bound(d.begin(),d.end(),seq[i])-d.begin()]=seq[i];
        }
    }

    return d.size();
}

int main()
{
    scanf("%d", &N);
    seq.resize(N,0);
    for(int i=0;i<N;i++) scanf("%d", &seq[i]);

    printf("%d\n", solve());
}
