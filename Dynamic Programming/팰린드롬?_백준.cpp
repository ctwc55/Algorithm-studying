#include <bits/stdc++.h>
#define MAXN 2000

using namespace std;

int N, M;
int d[MAXN][MAXN];
vector<int> seq;
queue< pair<int,int> > chk;

int solve(int S, int E){
   for(int i=0;i<=(E-S)/2;i++){
        chk.push({S+i,E-i});
        if(d[S+i][E-i]==1) break;
        if(d[S+i][E-i]==-1||seq[S+i]!=seq[E-i]){
            while(!chk.empty()){
                d[chk.front().first][chk.front().second]=-1;
                chk.pop();
            }
            return 0;
        }
    }
    while(!chk.empty()){
        d[chk.front().first][chk.front().second]=1;
        chk.pop();
    }
    return 1;
}

int main()
{
    int S, E;
    scanf("%d", &N);
    seq.resize(N,0);
    for(int i=0;i<N;i++) scanf("%d", &seq[i]);
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        scanf("%d %d", &S, &E);
        printf("%d\n", solve(S-1,E-1));
    }
}
