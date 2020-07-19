#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int init(vector<int> &seq, vector<int> &seg_tree, int node, int s, int e){
    if(s==e) return seg_tree[node]=seq[s];
    else return seg_tree[node]=min(init(seq,seg_tree,node*2,s,(s+e)/2),init(seq,seg_tree,node*2+1,(s+e)/2+1,e));
}

int update(vector<int> &seg_tree, int node, int s, int e, int idx, int chg){
    int cmp1, cmp2;

    if(idx<s||idx>e) return seg_tree[node];
    if(s==e) return seg_tree[node]=chg;

    cmp1=update(seg_tree,node*2,s,(s+e)/2,idx,chg);
    cmp2=update(seg_tree,node*2+1,(s+e)/2+1,e,idx,chg);
    return seg_tree[node]=min(cmp1,cmp2);
}

int findMin(vector<int> &seg_tree, int node, int s, int e, int l, int r){
    if(l>e||r<s) return INF;
    if(l<=s&&e<=r) return seg_tree[node];
    return min(findMin(seg_tree,node*2,s,(s+e)/2,l,r),findMin(seg_tree,node*2+1,(s+e)/2+1,e,l,r));
}

int main()
{
    int N, M;

    scanf("%d", &N);
    vector<int> seq(N);
    for(int i=0;i<N;i++) scanf("%d", &seq[i]);
    int depth=(int)ceil(log2(N));
    int tree_size=(1<<(depth+1));
    vector<int> seg_tree(tree_size,0);

    init(seq,seg_tree,1,0,N-1);

    scanf("%d", &M);
    for(int i=0;i<M;i++){
        int q, a, b;
        scanf("%d %d %d", &q, &a, &b);

        if(q==1) update(seg_tree,1,0,N-1,a-1,b);
        else printf("%d\n", findMin(seg_tree,1,0,N-1,a-1,b-1));
    }
}
