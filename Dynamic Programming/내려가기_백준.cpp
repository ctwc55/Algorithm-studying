#include <bits/stdc++.h>

using namespace std;

int N, max_score[3], min_score[3];

pair<int,int> solve(){
    int input[3], update[3];

    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++) scanf("%d", &input[j]);

        update[0]=max(max_score[0],max_score[1])+input[0];
        update[1]=max(max(max_score[0],max_score[1]),max_score[2])+input[1];
        update[2]=max(max_score[1],max_score[2])+input[2];
        for(int j=0;j<3;j++) max_score[j]=update[j];

        update[0]=min(min_score[0],min_score[1])+input[0];
        update[1]=min(min(min_score[0],min_score[1]),min_score[2])+input[1];
        update[2]=min(min_score[1],min_score[2])+input[2];
        for(int j=0;j<3;j++) min_score[j]=update[j];
    }

    sort(max_score,max_score+3);
    sort(min_score,min_score+3);

    return {max_score[2],min_score[0]};
}

int main()
{
    pair<int,int> ans;

    scanf("%d", &N);

    ans=solve();

    printf("%d %d\n", ans.first, ans.second);
}
