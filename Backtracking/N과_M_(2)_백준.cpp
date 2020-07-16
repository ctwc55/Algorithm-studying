#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;

void solve(int num, int len){
    v.push_back(num);

    if(len==M){
        for(int i=0;i<M;i++) printf("%d ", v[i]);
        printf("\n");
        v.pop_back();
        return;
    }

    for(int i=num+1;i<=N;i++) solve(i,len+1);

    v.pop_back();

    return;
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i=1;i<=N-M+1;i++) solve(i,1);
}
