#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

int K, M, P;
vector< vector<int> > strahler;
vector<int> in, maxo, order;
queue<int> topo;

int solve(){
    for(int i=1;i<=M;i++){
        if(in[i]==0){
            order[i]=1;
            topo.push(i);
        }
    }

    int tf;
    while(!topo.empty()){
        tf=topo.front();
        for(int j=0;j<strahler[tf].size();j++){
            int node=strahler[tf][j];
            in[node]--;
            if(order[tf]>maxo[node]||order[tf]==order[node]&&maxo[node]<order[node]){
                maxo[node]=order[tf];
                order[node]=order[tf];
            }
            else if(order[tf]==order[node]&&maxo[node]==order[node]) order[node]++;
            if(in[node]==0) topo.push(node);
        }
        topo.pop();
    }

    return order[tf];
}

int main()
{
    int T, a, b;

    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d", &K, &M, &P);
        strahler.clear();
        strahler.resize(M+1);
        order.clear();
        order.resize(M+1);
        maxo.clear();
        maxo.resize(M+1);
        in.resize(M+1);
        for(int i=0;i<P;i++){
            scanf("%d %d", &a, &b);
            strahler[a].push_back(b);
            in[b]++;
        }

        printf("%d %d\n", K, solve());
    }
}
