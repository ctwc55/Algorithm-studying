#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int prime[MAXN];

int main()
{
    int n, k, i, j, ans=0, pass=0;

    scanf("%d %d", &n, &k);

    i=2;
    while(i<MAXN){
        for(j=i;j<=n;j+=i){
            if(prime[j]==0){
                prime[j]=1;
                ans++;
            }
            if(ans==k){
                pass=1;
                break;
            }
        }
        if(pass==1) break;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    printf("%d\n", j);
}
