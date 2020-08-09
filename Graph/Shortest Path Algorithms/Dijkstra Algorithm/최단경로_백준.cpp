#include <bits/stdc++.h>
#define MAXN 20000
#define INF 1000000000

using namespace std;

int V, E, K;
vector< vector< pair<int,int> > > graph;
vector<int> d;
multimap<int,int> pq;

void solve(){
    int ans=INF;

    d[K]=0;
    pq.insert(make_pair(d[K],K));

    while(!pq.empty()){
        int dept=pq.begin()->second;
        for(int i=0;i<graph[dept].size();i++){
            int ariv=graph[dept][i].first;

            if(d[dept]+graph[dept][i].second<d[ariv]){
                d[ariv]=d[dept]+graph[dept][i].second;
                pq.insert(make_pair(d[ariv],ariv));
            }
        }
        pq.erase(pq.begin());
    }

    return;
}

int main()
{
    int u, v, w;
    int ans;

    scanf("%d %d", &V, &E);
    graph.resize(V+1,{});
    d.resize(V+1,INF);
    scanf("%d", &K);
    for(int i=0;i<E;i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v,w});
    }

    solve();

    for(int i=1;i<=V;i++){
        if(d[i]!=INF) printf("%d\n", d[i]);
        else printf("INF\n");
    }
}
