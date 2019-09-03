#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

vector<int> graph[10001];
int visit[10001];
int node, ans[10001];
int max_cnt=-MAXN, cnt;

void dfs(int n){
    if(visit[n]==1) return;
    visit[n]=1;
    cnt++;
    for(int i=0;i<graph[n].size();i++) dfs(graph[n][i]);
    return;
}

int main()
{
    int m, a, b;

    scanf("%d %d", &node, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        graph[b].push_back(a);
    }

    for(int i=1;i<=node;i++){
        cnt=0;
        dfs(i);
        if(max_cnt<cnt){
            for(int j=1;j<=node;j++) ans[j]=0;
            max_cnt=cnt;
            ans[i]=1;
        }
        else if(max_cnt==cnt) ans[i]=1;
        for(int j=1;j<=node;j++) visit[j]=0;
    }

    for(int i=1;i<=node;i++) if(ans[i]==1) printf("%d ", i);
}
