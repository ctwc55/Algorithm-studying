#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int N;
vector<int> A, d1, d2;

int solve(){
    int ans=-INF;
    for(int i=-1;i<N;i++){
        if(i>=0&&(d1.empty()||d1.back()<A[i])) d1.push_back(A[i]);
        else if(i>=0) *lower_bound(d1.begin(),d1.end(),A[i])=A[i];

        d2.clear();
        for(int j=N-1;j>i;j--){
            if(d2.empty()||d2.back()<A[j]) d2.push_back(A[j]);
            else *lower_bound(d2.begin(),d2.end(),A[j])=A[j];
        }

        int tmp=d1.size()+d2.size();
        if(d1.empty()||d2.empty()) ans=max(ans,tmp);
        else if(d1.back()!=d2.back()) ans=max(ans,tmp);
    }

    return ans;
}

int main()
{
    scanf("%d", &N);
    A.resize(N,0);
    for(int i=0;i<N;i++) scanf("%d", &A[i]);

    printf("%d\n", solve());
}
