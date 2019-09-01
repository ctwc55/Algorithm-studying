#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

vector<int> graph[10001];
int visit[10001];
int node, ans[10001];
int max_cnt=-MAXN;

void dfs(int n, int cnt, int deep){
    if(visit[n]==1) return;
    visit[n]=1;
    if(max_cnt<cnt){
        cout<<n<<" "<<cnt<<endl;
        for(int i=1;i<=node;i++) ans[i]=0;
        max_cnt=cnt;
        ans[n]=1;
    }
    else if(max_cnt==cnt) ans[n]=1;
    for(int i=0;i<graph[n].size();i++) dfs(graph[n][i],cnt+1,deep+1);
    return;
}

int main()
{
    int m, a, b;

    scanf("%d %d", &node, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
    }

    for(int i=1;i<=node;i++){
        cnt=0;
        dfs(i,0,0);
        for(int j=1;j<=node;j++) visit[j]=0;
    }

    for(int i=1;i<=node;i++) if(ans[i]==1) printf("%d ", i);
}
