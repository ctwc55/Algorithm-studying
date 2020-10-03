#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

typedef struct{
    int a, b;
    double c;
} INFO;

int n;
double stars[MAXN][2];
vector<int> parent;
vector<INFO> edge;

bool cmp(INFO a, INFO b){
    if(a.c<b.c) return true;
    return false;
}

int findRoot(int x){
    int p;

    if(x==parent[x]) return x;
    p=findRoot(parent[x]);
    parent[x]=p;
    return p;
}

bool unionRoot(int x, int y){
    x=findRoot(x);
    y=findRoot(y);
    if(x!=y){
        parent[y]=x;
        return true;
    }
    return false;
}

double dist(int x, int y){
    return sqrt(pow(stars[x][0]-stars[y][0],2)+pow(stars[x][1]-stars[y][1],2));
}

double solve(){
    int idx=0;
    double ans=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edge.push_back({i,j,dist(i,j)});
        }
    }

    sort(edge.begin(),edge.end(),cmp);

    for(int i=0;i<n;i++) parent[i]=i;

    for(int i=0;i<edge.size();i++){
        if(unionRoot(edge[i].a,edge[i].b)){
            ans+=edge[i].c;
        }
    }

    return ans;
}

int main()
{
    scanf("%d", &n);
    parent.resize(n);
    for(int i=0;i<n;i++) scanf("%lf %lf", &stars[i][0], &stars[i][1]);

    printf("%.2lf\n", solve());
}
