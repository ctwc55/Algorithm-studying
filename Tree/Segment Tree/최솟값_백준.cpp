#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1000000001

using namespace std;

int num[MAXN];
int tree[3*MAXN];

int init(int idx, int s, int e){
    int mid=(s+e)/2;

    if(s==e) return tree[idx]=num[s];
    return tree[idx]=min(init(idx*2,s,mid),init(idx*2+1,mid+1,e));
}

int findMin(int idx, int s, int e, int l, int r){
    int mid=(s+e)/2;

    if(l>e||r<s) return INF;
    if(l<=s&&e<=r) return tree[idx];
    return min(findMin(idx*2,s,mid,l,r),findMin(idx*2+1,mid+1,e,l,r));
}

int main()
{
    int n, m, a, b;

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &num[i]);

    init(1,0,n-1);

    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", findMin(1,0,n-1,a-1,b-1));
    }
}
