#include <bits/stdc++.h>

using namespace std;

int n, k, ord=0;
vector<int> ans;

void solve(int num){
    if(ord==k) return;
    if(num>n) return;
    if(num==n){
        ord++;
        if(ord==k){
            for(int i=0;i<ans.size()-1;i++){
                printf("%d+", ans[i]);
            }
            printf("%d\n", ans.back());
            return;
        }
        return;
    }

    for(int i=1;i<=3;i++){
        ans.push_back(i);
        solve(num+i);
        ans.pop_back();
    }

    return;
}

int main()
{
    scanf("%d %d", &n, &k);

    solve(0);

    if(ord!=k) printf("-1\n");
}
