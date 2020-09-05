#include <bits/stdc++.h>

using namespace std;

int N, M;
vector< vector<int> > problem;
vector<int> in;
set<int> topo;

void solve(){
    for(int i=1;i<=N;i++){
        if(in[i]==0) topo.insert(i);
    }

    for(int i=0;i<N;i++){
        int now=*topo.begin();
        printf("%d ", now);
        topo.erase(topo.begin());
        for(int j=0;j<problem[now].size();j++){
            int node=problem[now][j];
            in[node]--;
            if(in[node]==0) topo.insert(node);
        }
    }

    printf("\n");

    return;
}

int main()
{
    int A, B;

    scanf("%d %d", &N, &M);
    problem.resize(N+1);
    in.resize(N+1);
    for(int i=0;i<M;i++){
        scanf("%d %d", &A, &B);
        problem[A].push_back(B);
        in[B]++;
    }

    solve();
}
