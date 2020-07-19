#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

pair<int,int> init(vector<int> &seq, vector< pair<int,int> > &seg_tree, int node, int s, int e){
    pair<int,int> cmp1, cmp2;

    if(s==e) return seg_tree[node]=make_pair((seq[s]+1)%2,seq[s]%2);
    else{
        cmp1=init(seq,seg_tree,node*2,s,(s+e)/2);
        cmp2=init(seq,seg_tree,node*2+1,(s+e)/2+1,e);
        return seg_tree[node]=make_pair(cmp1.first+cmp2.first,cmp1.second+cmp2.second);
    }
}

pair<int,int> update(vector< pair<int,int> > &seg_tree, int node, int s, int e, int idx, pair<int,int> chg){
    pair<int,int> cmp1, cmp2;

    if(idx<s||idx>e) return seg_tree[node];
    if(s==e){
        seg_tree[node]=chg;
        return seg_tree[node];
    }

    cmp1=update(seg_tree,node*2,s,(s+e)/2,idx,chg);
    cmp2=update(seg_tree,node*2+1,(s+e)/2+1,e,idx,chg);
    return seg_tree[node]=make_pair(cmp1.first+cmp2.first,cmp1.second+cmp2.second);
}

pair<int,int> findEvenOdd(vector< pair<int,int> > &seg_tree, int node, int s, int e, int l, int r){
    pair<int,int> cmp1, cmp2;

    if(l>e||r<s) return {0,0};
    if(l<=s&&e<=r) return seg_tree[node];

    cmp1=findEvenOdd(seg_tree,node*2,s,(s+e)/2,l,r);
    cmp2=findEvenOdd(seg_tree,node*2+1,(s+e)/2+1,e,l,r);
    return {cmp1.first+cmp2.first,cmp1.second+cmp2.second};
}

int main()
{
    int N, M;

    scanf("%d", &N);
    vector<int> seq(N);
    for(int i=0;i<N;i++) scanf("%d", &seq[i]);
    int depth=(int)ceil(log2(N));
    int tree_size=(1<<(depth+1));
    vector< pair<int,int> > seg_tree(tree_size,{0,0}); //first:even second:odd

    init(seq,seg_tree,1,0,N-1);

    scanf("%d", &M);
    for(int i=0;i<M;i++){
        int q, a, b;
        scanf("%d %d %d", &q, &a, &b);

        if(q==1) update(seg_tree,1,0,N-1,a-1,{(b+1)%2,b%2});
        else if(q==2) printf("%d\n", findEvenOdd(seg_tree,1,0,N-1,a-1,b-1).first);
        else printf("%d\n", findEvenOdd(seg_tree,1,0,N-1,a-1,b-1).second);
    }
}
