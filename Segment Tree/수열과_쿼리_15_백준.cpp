#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1000000001

using namespace std;

int num[MAXN];
pair<int,int> tree[3*MAXN]; //first:index second:value

int init(int idx, int s, int e){
    int mid=(s+e)/2, tmp1, tmp2;

    if(s==e){
        tree[idx].first=s;
        return tree[idx].second=num[s];
    }
    tmp1=init(idx*2,s,mid);
    tmp2=init(idx*2+1,mid+1,e);
    if(tmp1<=tmp2){
        tree[idx].first=tree[idx*2].first;
        return tree[idx].second=tmp1;
    }
    else{
        tree[idx].first=tree[idx*2+1].first;
        return tree[idx].second=tmp2;
    }
}

void update(int idx, int s, int e, int pos, int v){
    int mid=(s+e)/2;

    if(pos<s||pos>e) return;

    if(s==e) tree[idx].second=v;
    if(s!=e){
        update(idx*2,s,mid,pos,v);
        update(idx*2+1,mid+1,e,pos,v);
        tree[idx].first=(tree[idx*2].second<=tree[idx*2+1].second)?tree[idx*2].first:tree[idx*2+1].first;
        tree[idx].second=min(tree[idx*2].second,tree[idx*2+1].second);
    }
}

int main()
{
    int n, m, q, a, v;

    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &num[i]);

    init(1,0,n-1);

    scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf("%d", &q);
        if(q==1){
            scanf("%d %d", &a, &v);
            update(1,0,n-1,a-1,v);
        }
        else printf("%d\n", tree[1].first+1);
    }
}
