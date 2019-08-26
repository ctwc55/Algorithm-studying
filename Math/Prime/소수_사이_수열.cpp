#include <bits/stdc++.h>
#define MAXN 2000000

using namespace std;

int prime[MAXN];

int main()
{
    int test_case, k, i, j, p;

    scanf("%d", &test_case);

    i=2;
    while(i<MAXN){
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    for(i=0;i<test_case;i++){
        scanf("%d", &k);
        if(prime[k]==0){
            printf("0\n");
            continue;
        }
        else{
            for(j=k;prime[j]!=0;j--);
            for(p=k;prime[p]!=0;p++);
            printf("%d\n", p-j);
        }
    }

}
