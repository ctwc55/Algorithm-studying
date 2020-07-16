#include <bits/stdc++.h>

using namespace std;

int N, M;
int nums[9], chk[9];
vector<int> v;

void solve(int num, int len){
    if(chk[num]) return;

    v.push_back(nums[num]);
    chk[num]=1;

    if(len==M){
        for(int i=0;i<M;i++) printf("%d ", v[i]);
        printf("\n");
        v.pop_back();
        chk[num]=0;
        return;
    }

    for(int i=0;i<N;i++) solve(i,len+1);

    v.pop_back();
    chk[num]=0;

    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++) scanf("%d", &nums[i]);

    sort(nums,nums+N);
    for(int i=0;i<N;i++) solve(i,1);
}
