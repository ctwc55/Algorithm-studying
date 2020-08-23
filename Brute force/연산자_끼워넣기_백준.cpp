#include <bits/stdc++.h>
#define MAXN 100
#define INF 2000000000

using namespace std;

int N, A[MAXN], C[4];
int ansm=INF, ansM=-INF;

void solve(int num, int deep){
    if(deep==N){
        ansm=min(ansm,num);
        ansM=max(ansM,num);

        return;
    }

    for(int i=0;i<4;i++){
        if(C[i]>0){
            C[i]--;
            if(i==0) solve(num+A[deep],deep+1);
            else if(i==1) solve(num-A[deep],deep+1);
            else if(i==2) solve(num*A[deep],deep+1);
            else solve(num/A[deep],deep+1);
            C[i]++;
        }
    }

    return;
}

int main()
{
    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &A[i]);
    for(int i=0;i<4;i++) scanf("%d", &C[i]);

    solve(A[0],1);

    printf("%d\n%d\n", ansM, ansm);
}
