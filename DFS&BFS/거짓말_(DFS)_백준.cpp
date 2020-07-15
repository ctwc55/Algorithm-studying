#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int net[51][51], visit[51];
set<int> know;
vector< vector<int> > parties;

void dfs(int x, int chk){
    if(x<1||x>N) return;
    if(visit[x]==chk) return;

    visit[x]=chk;
    if(chk==2||know.find(x)!=know.end()){
        know.insert(x);
        for(int i=1;i<=N;i++) if(net[x][i]) dfs(i,2);
    }
    else{
        for(int i=1;i<=N;i++) if(net[x][i]) dfs(i,1);
    }

    return;
}

int solve(){
    int ans=0, fail;

    for(int i=1;i<=N;i++) dfs(i,1);

    for(int i=0;i<M;i++){
        fail=0;
        for(int j=0;j<parties[i].size();j++){
            if(know.find(parties[i][j])!=know.end()){
                fail=1;
                break;
            }
        }
        if(!fail) ans++;
    }

    return ans;
}

int main()
{
    int input, people;
    vector<int> party;

    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    for(int i=0;i<K;i++){
        scanf("%d", &input);
        know.insert(input);
    }
    for(int i=0;i<M;i++){
        scanf("%d", &people);
        for(int j=0;j<people;j++){
            scanf("%d", &input);
            party.push_back(input);
            net[party[0]][input]=1;
            net[input][party[0]]=1;
        }
        parties.push_back(party);
        party.clear();
    }

    printf("%d\n", solve());
}
