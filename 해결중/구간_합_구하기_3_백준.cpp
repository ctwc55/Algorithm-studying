#include <bits/stdc++.h>
#define MAXN 2000000

using namespace std;

int num[MAXN];
int tree[2*MAXN];

int init(int idx, int s, int e){
    int mid=(s+e)/2;

    if(s==e) return tree[idx]=num[s];
    return tree[idx]=init(idx*2,s,mid)+init(idx*2+1,mid+1,e);
}

int sum(int idx, int s, int e, int l, int r){
    int mid=(s+e)/2;

    if(l>e||r<s) return 0;
    if(l<=s&&e<=r) return tree[idx];
    return sum(idx*2,s,mid,l,r)+sum(idx*2+1,mid+1,e,l,r);
}

void update(int idx, int s, int e, int pos, int diff){
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
    int n, m, w, x1, x2, y1, y2, c, diff, trf1, trf2, ans;

    scanf("%d %d", &n, &m);
    for(int i=0;i<n*n;i++) scanf("%d", &num[i]);

    init(1,0,n*n-1);

    for(int i=0;i<m;i++){
        scanf("%d", &w);
        if(w==0){
            scanf("%d %d %d", &x1, &y1, &c);
            trf1=(x1-1)*n+(y1-1);
            diff=c-num[trf1];
            num[trf1]=c;
            update(1,0,n*n-1,trf1,diff);
        }
        else{
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            ans=0;
            for(int j=0;j<=x2-x1;j++){
                trf1=(x1+j-1)*n+(y1-1);
                trf2=(x1+j-1)*n+(y2-1);
                ans+=sum(1,0,n*n-1,trf1,trf2);
            }
            printf("%d\n", ans);
        }
    }
}
