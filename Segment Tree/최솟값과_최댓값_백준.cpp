#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1000000001

using namespace std;

int num[MAXN];
int min_tree[3*MAXN], max_tree[3*MAXN];

int initMin(int idx, int s, int e){
    int mid=(s+e)/2;

    if(s==e) return min_tree[idx]=num[s];
    return min_tree[idx]=min(initMin(idx*2,s,mid),initMin(idx*2+1,mid+1,e));
}

int initMax(int idx, int s, int e){
    int mid=(s+e)/2;

    if(s==e) return max_tree[idx]=num[s];
    return max_tree[idx]=max(initMax(idx*2,s,mid),initMax(idx*2+1,mid+1,e));
}

int findMin(int idx, int s, int e, int l, int r){
    int mid=(s+e)/2;

    if(l>e||r<s) return INF;
    if(l<=s&&e<=r) return min_tree[idx];
    return min(findMin(idx*2,s,mid,l,r),findMin(idx*2+1,mid+1,e,l,r));
}

int findMax(int idx, int s, int e, int l, int r){
    int mid=(s+e)/2;

    if(l>e||r<s) return -INF;
    if(l<=s&&e<=r) return max_tree[idx];
    return max(findMax(idx*2,s,mid,l,r),findMax(idx*2+1,mid+1,e,l,r));
}

int main()
{
    int n, m, a, b;

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &num[i]);

    initMin(1,0,n-1);
    initMax(1,0,n-1);

    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        printf("%d %d\n", findMin(1,0,n-1,a-1,b-1), findMax(1,0,n-1,a-1,b-1));
    }
}
