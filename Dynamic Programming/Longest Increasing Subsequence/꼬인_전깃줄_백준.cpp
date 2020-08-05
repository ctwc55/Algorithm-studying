#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int N;
vector<int> v, d;

int solve(){
    d.push_back(v[0]);
    for(int i=1;i<N;i++){
        if(d[d.size()-1]<v[i]) d.push_back(v[i]);
        else d[lower_bound(d.begin(),d.end(),v[i])-d.begin()]=v[i];
    }

    return N-d.size();
}

int main()
{
    scanf("%d", &N);
    v.resize(N,0);
    for(int i=0;i<N;i++) scanf("%d", &v[i]);

    printf("%d\n", solve());
}
