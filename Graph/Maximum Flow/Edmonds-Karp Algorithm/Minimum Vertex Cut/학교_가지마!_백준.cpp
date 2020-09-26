#include <bits/stdc++.h>
#define MAXN 105
#define INF 1000000000

using namespace std;

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int N, M;
map< pair< pair<int,int>,pair<int,int> >,int> c, f;
char road[MAXN][MAXN];
map< pair<int,int>,vector< pair<int,int> > > cnvr;
map< pair<int,int>,pair<int,int> > bef;
queue< pair<int,int> > bfs;

void make_cnvr(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(road[i][j]=='#') continue;
            cnvr[{i,j}].push_back(make_pair(i+MAXN,j+MAXN));
            cnvr[{i+MAXN,j+MAXN}].push_back(make_pair(i,j));
            c[{{i,j},{i+MAXN,j+MAXN}}]=1;
            for(int k=0;k<4;k++){
                int x=i+dx[k], y=j+dy[k];
                if(x<0||x>=N||y<0||y>=M||road[x][y]=='#') continue;
                cnvr[{i+MAXN,j+MAXN}].push_back(make_pair(x,y));
                cnvr[{x,y}].push_back(make_pair(i+MAXN,j+MAXN));
                cnvr[{x+MAXN,y+MAXN}].push_back(make_pair(i,j));
                cnvr[{i,j}].push_back(make_pair(x+MAXN,y+MAXN));
                c[{{i+MAXN,j+MAXN},{x,y}}]=1;
                c[{{x+MAXN,y+MAXN},{i,j}}]=1;
            }
        }
    }

    return;
}

int solve(int sx, int sy, int tx, int ty){
    int ans=0, x;

    make_cnvr();

    while(1){
        bfs.push({sx+MAXN,sy+MAXN});
        bef.clear();

        while(!bfs.empty()){
            pair<int,int> node=bfs.front();
            vector< pair<int,int> > curr=cnvr[node];
            for(int i=0;i<curr.size();i++){
                int nextx=curr[i].first, nexty=curr[i].second;
                if(c[{{node.first,node.second},{nextx,nexty}}]-f[{{node.first,node.second},{nextx,nexty}}]>0&&bef.find({nextx,nexty})==bef.end()){
                    bfs.push({nextx,nexty});
                    bef[{nextx,nexty}]=make_pair(node.first,node.second);
                    if(nextx==tx&&nexty==ty) break;
                }
            }
            bfs.pop();
        }
        while(bfs.size()) bfs.pop();
        if(bef.find({tx,ty})==bef.end()) break;

        x=INF;
        for(pair<int,int> i=make_pair(tx,ty);i!=make_pair(sx+MAXN,sy+MAXN);i=bef[i]) x=min(x,c[{bef[i],i}]-f[{bef[i],i}]);
        for(pair<int,int> i=make_pair(tx,ty);i!=make_pair(sx+MAXN,sy+MAXN);i=bef[i]){
            f[{bef[i],i}]+=x;
            f[{i,bef[i]}]-=x;
        }

        ans+=x;
    }

    return ans;
}

int main()
{
    int sx, sy, tx, ty;

    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        getchar();
        for(int j=0;j<M;j++){
            scanf("%c", &road[i][j]);
            if(road[i][j]=='K'){
                sx=i;
                sy=j;
            }
            else if(road[i][j]=='H'){
                tx=i;
                ty=j;
            }
        }
    }

    if(abs(sx-tx)+abs(sy-ty)==1) printf("-1\n");
    else printf("%d\n", solve(sx,sy,tx,ty));
}
