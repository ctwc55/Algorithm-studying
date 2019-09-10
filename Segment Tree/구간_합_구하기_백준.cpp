#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

long long num[MAXN];
long long tree[3*MAXN];

long long init(int idx, int s, int e){
    int mid=(s+e)/2;

    if(s==e) return tree[idx]=num[s];
    return tree[idx]=init(idx*2,s,mid)+init(idx*2+1,mid+1,e);
}

long long sum(int idx, int s, int e, int l, int r){
    int mid=(s+e)/2;

    if(l>e||r<s) return 0;
    if(l<=s&&e<=r) return tree[idx];
    return sum(idx*2,s,mid,l,r)+sum(idx*2+1,mid+1,e,l,r);
}

void update(int idx, int s, int e, int pos, long long diff){
    int mid=(s+e)/2;

    if(pos<s||pos>e) return;

    tree[idx]=tree[idx]+diff;
    if(s!=e){
        update(idx*2,s,mid,pos,diff);
        update(idx*2+1,mid+1,e,pos,diff);
    }
}

int main()
{
    int n, m, k, a, b;
    long long c, diff;

    scanf("%d %d %d", &n, &m, &k);
    for(int i=0;i<n;i++) scanf("%lld", &num[i]);

    init(1,0,n-1);

    for(int i=0;i<m+k;i++){
        scanf("%d %d %lld", &a, &b, &c);
        if(a==1){
            diff=c-num[b-1];
            num[b-1]=c;
            update(1,0,n-1,b-1,diff);
        }
        else printf("%lld\n", sum(1,0,n-1,b-1,(int)c-1));
    }
}
