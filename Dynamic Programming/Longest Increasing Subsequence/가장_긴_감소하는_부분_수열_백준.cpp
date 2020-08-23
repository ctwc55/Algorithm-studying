#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A, d;

int solve(){
    for(vector<int>::reverse_iterator rit=A.rbegin();rit!=A.rend();rit++){
        if(d.empty()||d.back()<*rit) d.push_back(*rit);
        else *lower_bound(d.begin(),d.end(),*rit)=*rit;
    }

    return d.size();
}

int main()
{
    scanf("%d", &N);
    A.resize(N,0);
    for(int i=0;i<N;i++) scanf("%d", &A[i]);

    printf("%d\n", solve());
}
