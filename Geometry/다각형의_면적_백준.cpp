#include <bits/stdc++.h>
#define MAXN 10000

using namespace std;

int N;
double arr[MAXN][2];

double solve(){
    double ans=0.0;

    for(int i=0;i<N;i++){
        ans+=(arr[i][0]*arr[(i+1)%N][1]-arr[(i+1)%N][0]*arr[i][1]);
    }

    return abs(ans)/2;
}

int main()
{
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%lf %lf", &arr[i][0], &arr[i][1]);

    printf("%.1lf\n", solve());
}
