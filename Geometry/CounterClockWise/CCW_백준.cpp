#include <bits/stdc++.h>

using namespace std;

int P[3][2];

int solve(){
    int cal=(P[1][0]-P[0][0])*(P[2][1]-P[0][1])-(P[1][1]-P[0][1])*(P[2][0]-P[0][0]);

    if(cal>0) return 1;
    if(cal==0) return 0;
    return -1;
}

int main()
{
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            scanf("%d", &P[i][j]);
        }
    }

    printf("%d\n", solve());
}
