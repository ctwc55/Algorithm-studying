#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int prime[MAXN];

int main()
{
    int test_case, i, j;
    int n, sub, ans;

    scanf("%d", &test_case);

    i=2;
    while(i<MAXN){
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    for(i=0;i<test_case;i++){
        scanf("%d", &n);
        sub=MAXN;
        for(j=2;j<n;j++){
            if(prime[j]==0&&prime[n-j]==0&&sub>abs(n-2*j)){
                sub=abs(n-2*j);
                ans=j;
            }
        }
        printf("%d %d\n", min(ans,n-ans), max(ans,n-ans));
    }
}
