#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int prime[MAXN]={1,1,};

int main()
{
    int n, i, j;

    i=2;
    while(i<MAXN){
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    while(1){
        scanf("%d", &n);
        if(n==0) break;
        for(j=2;j<n;j++){
            if(prime[j]==0&&prime[n-j]==0) break;
        }
        if(j==2) printf("Goldbach's conjecture is wrong.\n");
        else printf("%d = %d + %d\n", n, j, n-j);
    }
}
