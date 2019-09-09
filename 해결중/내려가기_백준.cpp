#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int main()
{
    int n, memo_min[2][3]={}, memo_max[2][3]={};
    int ans_min=MAXN, ans_max=-MAXN;

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(i==1){
                scanf("%d", &memo_min[1][j]);
                memo_max[1][j]=memo_min[1][j];
            }
            else{
                scanf("%d", &memo_min[0][j]);
                memo_max[0][j]=memo_min[0][j];
            }
        }
        if(n>1&&i==0) continue;
        memo_max[1][0]=max(memo_max[1][0]+memo_max[0][0],memo_max[1][0]+memo_max[0][1]);
        memo_min[1][0]=min(memo_min[1][0]+memo_min[0][0],memo_min[1][0]+memo_min[0][1]);

        memo_max[1][1]=max(memo_max[1][1]+memo_max[0][0],max(memo_max[1][1]+memo_max[0][1],memo_max[1][1]+memo_max[0][2]));
        memo_min[1][1]=min(memo_min[1][1]+memo_min[0][0],min(memo_min[1][1]+memo_min[0][1],memo_min[1][1]+memo_min[0][2]));

        memo_max[1][2]=max(memo_max[1][2]+memo_max[0][2],memo_max[1][2]+memo_max[0][1]);
        memo_min[1][2]=min(memo_min[1][2]+memo_min[0][2],memo_min[1][2]+memo_min[0][1]);
    }

    for(int i=0;i<3;i++){
        ans_min=min(ans_min,memo_min[1][i]);
        ans_max=max(ans_max,memo_max[1][i]);
    }

    printf("%d %d\n", ans_max, ans_min);
}
