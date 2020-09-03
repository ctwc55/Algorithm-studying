#include <bits/stdc++.h>
#define MAXN 32000

using namespace std;

int N, M, in[MAXN+1];
vector< vector<int> > student;
vector<int> ans;
queue<int> topo;

void solve(){
    for(int i=1;i<=N;i++){
        if(in[i]==0) topo.push(i);
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<student[topo.front()].size();j++){
            int node=student[topo.front()][j];
            in[node]--;
            if(in[node]==0) topo.push(node);
        }
        ans.push_back(topo.front());
        topo.pop();
    }
}

int main()
{
    int a, b;

    scanf("%d %d", &N, &M);
    student.resize(N+1);
    for(int i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        student[a].push_back(b);
        in[b]++;
    }

    solve();

    for(int i=0;i<N;i++) printf("%d ", ans[i]);
    printf("\n");
}
