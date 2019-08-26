#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int prime[MAXN];

int main()
{
    long long int a, b, k, tmp;
    int i, j, ans=0;
    scanf("%lld %lld", &a, &b);

    i=2;
    while(i<MAXN){
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    for(i=2;i<MAXN;i++){
        if(prime[i]==0){
            tmp=1LL*i*i;
            while(tmp<a) tmp*=i;
            for(k=tmp;k<=b&&k%tmp==0;k*=(1LL*i)) ans++;
        }
    }

    printf("%d\n", ans);
}
