#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

vector<int> init(vector<int> &seq, vector< vector<int> > &seg_tree, int node, int s, int e){
    vector<int> cmp1, cmp2;

    if(s==e) return seg_tree[node]={seq[s]};
    else{
        cmp1=init(seq,seg_tree,node*2,s,(s+e)/2);
        cmp2=init(seq,seg_tree,node*2+1,(s+e)/2+1,e);
        seg_tree[node].resize(cmp1.size()+cmp2.size());
        merge(cmp1.begin(),cmp1.end(),cmp2.begin(),cmp2.end(),seg_tree[node].begin());
        return seg_tree[node];
    }
}

int findUpKNum(vector< vector<int> > &seg_tree, int node, int s, int e, int l, int r, int k){
    if(l>e||r<s) return 0;
    if(l<=s&&e<=r) return seg_tree[node].end()-upper_bound(seg_tree[node].begin(),seg_tree[node].end(),k);
    return findUpKNum(seg_tree,node*2,s,(s+e)/2,l,r,k)+findUpKNum(seg_tree,node*2+1,(s+e)/2+1,e,l,r,k);
}

int main()
{
    int N, M, ans=0;

    scanf("%d", &N);
    vector<int> seq(N);
    for(int i=0;i<N;i++) scanf("%d", &seq[i]);
    int depth=(int)ceil(log2(N));
    int tree_size=(1<<(depth+1));
    vector< vector<int> > seg_tree(tree_size,{0});

    init(seq,seg_tree,1,0,N-1);

    scanf("%d", &M);
    for(int i=0;i<M;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        a=a^ans;
        b=b^ans;
        c=c^ans;
        ans=findUpKNum(seg_tree,1,0,N-1,a-1,b-1,c);
        printf("%d\n", ans);
    }
}
