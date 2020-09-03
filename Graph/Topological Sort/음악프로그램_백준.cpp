#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

int N, M, in[MAXN+1];
vector< vector<int> > singer;
vector<int> ans;
queue<int> topo;

void solve(){
    for(int i=1;i<=N;i++){
        if(in[i]==0) topo.push(i);
    }

    for(int i=0;i<N;i++){
        if(topo.empty()){
            topo.push(0);
            break;
        }
        for(int j=0;j<singer[topo.front()].size();j++){
            int node=singer[topo.front()][j];
            in[node]--;
            if(in[node]==0) topo.push(node);
        }
        ans.push_back(topo.front());
        topo.pop();
    }
}

int main()
{
    int a, b, s;

    scanf("%d %d", &N, &M);
    singer.resize(N+1);
    for(int i=0;i<M;i++){
        scanf("%d", &s);
        for(int j=0;j<s;j++){
            if(j==0) scanf("%d", &a);
            else{
                scanf("%d", &b);
                singer[a].push_back(b);
                in[b]++;
                a=b;
            }
        }
    }

    solve();

    if(!topo.empty()) printf("0\n");
    else for(int i=0;i<N;i++) printf("%d\n", ans[i]);
}
