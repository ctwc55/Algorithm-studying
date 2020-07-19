#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

void init(vector<int> &seq, vector<long long> &seg_tree, int node, int s, int e){
    if(s==e) seg_tree[node]=seq[s];
    else{
        init(seq,seg_tree,node*2,s,(s+e)/2);
        init(seq,seg_tree,node*2+1,(s+e)/2+1,e);
    }
    return;
}

void update(vector<long long> &seg_tree, int node, int s, int e, int l, int r, int add){
    if(r<s||l>e) return;
    if(s==e) seg_tree[node]+=add;
    else if(l<=s&&e<=r) seg_tree[node]+=add;
    else{
        update(seg_tree,node*2,s,(s+e)/2,l,r,add);
        update(seg_tree,node*2+1,(s+e)/2+1,e,l,r,add);
    }
    return;
}

long long findX(vector<long long> &seg_tree, int node, int s, int e, int idx){
    if(idx<s||idx>e) return 0;
    if(s==e&&s==idx) return seg_tree[node];
    return seg_tree[node]+findX(seg_tree,node*2,s,(s+e)/2,idx)+findX(seg_tree,node*2+1,(s+e)/2+1,e,idx);
}

int main()
{
    int N, M;

    scanf("%d", &N);
    vector<int> seq(N);
    for(int i=0;i<N;i++) scanf("%d", &seq[i]);
    int depth=(int)ceil(log2(N));
    int tree_size=(1<<(depth+1));
    vector<long long> seg_tree(tree_size,0);

    init(seq,seg_tree,1,0,N-1);

    scanf("%d", &M);
    for(int i=0;i<M;i++){
        int q, a, b, c;
        scanf("%d", &q);

        if(q==1){
            scanf("%d %d %d", &a, &b, &c);
            update(seg_tree,1,0,N-1,a-1,b-1,c);
        }
        else{
            scanf("%d", &a);
            printf("%lld\n",findX(seg_tree,1,0,N-1,a-1));
        }
    }
}
