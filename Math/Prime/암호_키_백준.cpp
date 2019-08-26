#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int prime[MAXN];

int main()
{
    int test_case, i, j, pass;
    long long int s;

    scanf("%d", &test_case);

    i=2;
    while(i<MAXN){
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    for(i=0;i<test_case;i++){
        scanf("%lld", &s);
        pass=0;
        for(j=2;j<MAXN&&s>0;j++){
            if(prime[j]==0&&s%j==0){
                if(j>1000000) s/=(1LL*j);
                else{
                    printf("NO\n");
                    pass=1;
                    break;
                }
            }
        }
        if(pass==0) printf("YES\n");
    }

}
