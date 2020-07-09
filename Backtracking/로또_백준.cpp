#include <bits/stdc++.h>

using namespace std;

int run=1;
vector<int> v, ans;

void solve(int idx, int len){
    if(len==6){
        for(int i=0;i<ans.size();i++) printf("%d ", ans[i]);
        printf("\n");
        return;
    }

    for(int i=idx;i<run;i++){
        ans.push_back(v[i]);
        solve(i+1,len+1);
        ans.pop_back();
    }

    return;
}

int main()
{
    int num;

    while(run){
        scanf("%d", &run);
        for(int i=0;i<run;i++){
            scanf("%d", &num);
            v.push_back(num);
        }
        solve(0,0);
        printf("\n");
        while(!v.empty()) v.pop_back();
    }
}
