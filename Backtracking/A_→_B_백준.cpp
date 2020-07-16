#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int A, B;

int solve(long long num, int idx){
    if(num>B) return MAXN;
    if(num==B) return idx;

    return min(solve(num*10+1,idx+1),solve(num*2,idx+1));
}

int main()
{
    int ans;

    scanf("%d %d", &A, &B);

    ans=solve(A,0);
    printf("%d\n", ans!=MAXN?ans+1:-1);
}
