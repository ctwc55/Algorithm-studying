#include <bits/stdc++.h>
#define MAXN 1000000
#define DIV 1000000009

using namespace std;

int n, d[MAXN+1];

int solve(int num){
    if(num<0) return 0;
    if(d[num]) return d[num];
    if(num==0) return 1;

    for(int i=1;i<=3;i++) d[num]=(d[num]+solve(num-i))%DIV;

    return d[num];
}

int main()
{
    int T;

    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
}
