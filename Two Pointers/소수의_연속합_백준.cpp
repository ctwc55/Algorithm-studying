#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int prime[MAXN];

int main()
{
    int n, i, j, s=1, e=1, sum=0, ans=0;

    scanf("%d", &n);

    i=2;
    while(i<MAXN){
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    while(e<MAXN){
        if(sum<n){
            while(prime[++e]==1);
            sum+=e;
        }
        else if(sum==n){
            ans++;
            while(prime[++e]==1);
            sum+=e;
            while(prime[++s]==1);
            sum-=s;
        }
        else{
            while(prime[++s]==1);
            sum-=s;
        }
    }

    printf("%d\n", ans);
}
