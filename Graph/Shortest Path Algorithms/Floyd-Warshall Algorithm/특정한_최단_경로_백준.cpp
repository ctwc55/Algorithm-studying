#include <bits/stdc++.h>
#define MAXN 800
#define INF 1000000

using namespace std;

int N, E, v1, v2;
int graph[MAXN+1][MAXN+1];

int solve(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }

    if(v1==1&&v2==N) return graph[1][N];
    else if(v1==1) return graph[1][v2]+graph[v2][N];
    else if(v2==N) return graph[1][v1]+graph[v1][N];
    return min(graph[1][v1]+graph[v1][v2]+graph[v2][N],graph[1][v2]+graph[v2][v1]+graph[v1][N]);
}

int main()
{
    int a, b, c;
    int ans;

    scanf("%d %d", &N, &E);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) graph[i][j]=INF;
    }

    for(int i=0;i<E;i++){
        scanf("%d %d %d", &a, &b, &c);
        graph[a][b]=c;
        graph[b][a]=c;
    }
    scanf("%d %d", &v1, &v2);

    ans=solve();
    printf("%d", ans<INF?ans:-1);
}
