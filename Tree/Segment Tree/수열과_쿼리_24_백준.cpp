#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

bool cmp(int a, int b){
    return a>b;
}

pair<int,int> init(vector<int> &seq, vector< pair<int,int> > &seg_tree, int node, int s, int e){
    pair<int,int> cmp1, cmp2;
    vector<int> max_cmp;

    if(s==e) return seg_tree[node]=make_pair(seq[s],-INF);
    else{
        cmp1=init(seq,seg_tree,node*2,s,(s+e)/2);
        cmp2=init(seq,seg_tree,node*2+1,(s+e)/2+1,e);
        max_cmp.push_back(cmp1.first);
        max_cmp.push_back(cmp1.second);
        max_cmp.push_back(cmp2.first);
        max_cmp.push_back(cmp2.second);
        sort(max_cmp.begin(),max_cmp.end(),cmp);
        return seg_tree[node]=make_pair(max_cmp[0],max_cmp[1]);
    }
}

pair<int,int> update(vector< pair<int,int> > &seg_tree, int node, int s, int e, int idx, int chg){
    pair<int,int> cmp1, cmp2;
    vector<int> max_cmp;

    if(idx<s||idx>e) return seg_tree[node];
    if(s==e) return seg_tree[node]=make_pair(chg,-INF);

    cmp1=update(seg_tree,node*2,s,(s+e)/2,idx,chg);
    cmp2=update(seg_tree,node*2+1,(s+e)/2+1,e,idx,chg);
    max_cmp.push_back(cmp1.first);
    max_cmp.push_back(cmp1.second);
    max_cmp.push_back(cmp2.first);
    max_cmp.push_back(cmp2.second);
    sort(max_cmp.begin(),max_cmp.end(),cmp);
    return seg_tree[node]=make_pair(max_cmp[0],max_cmp[1]);;
}

void maxSum(vector< pair<int,int> > &seg_tree, int node, int s, int e, int l, int r, vector<int> &max_cmp){
    if(r<s||l>e) max_cmp.push_back(-INF);
    else if(l<=s&&e<=r){
        max_cmp.push_back(seg_tree[node].first);
        max_cmp.push_back(seg_tree[node].second);
    }
    else{
        maxSum(seg_tree,node*2,s,(s+e)/2,l,r,max_cmp);
        maxSum(seg_tree,node*2+1,(s+e)/2+1,e,l,r,max_cmp);
    }
    return;
}

int main()
{
    int N, M;

    scanf("%d", &N);
    vector<int> seq(N), max_cmp;
    for(int i=0;i<N;i++) scanf("%d", &seq[i]);
    int depth=(int)ceil(log2(N));
    int tree_size=(1<<(depth+1));
    vector< pair<int,int> > seg_tree(tree_size,{0,0});

    init(seq,seg_tree,1,0,N-1);

    scanf("%d", &M);
    for(int i=0;i<M;i++){
        int q, a, b;
        scanf("%d %d %d", &q, &a, &b);

        if(q==1) update(seg_tree,1,0,N-1,a-1,b);
        else{
            max_cmp.clear();
            maxSum(seg_tree,1,0,N-1,a-1,b-1,max_cmp);
            sort(max_cmp.begin(),max_cmp.end(),cmp);
            printf("%d\n",max_cmp[0]+max_cmp[1]);
        }
    }
}
