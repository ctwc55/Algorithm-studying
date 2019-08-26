#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

int prime[MAXN];
int make[MAXN];
int ans[MAXN];

int main()
{
    int n, i, j, num, tmp, fail;

    scanf("%d", &n);

    i=2;
    while(i<MAXN){
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    for(i=2;i<=n;i++){
        if(i<MAXN&&prime[i]==0){
            num=i;
            fail=0;
            for(j=0;j<500;j++) make[j]=0;

            while(num!=1){
                if(ans[num]==1){
                    printf("%d\n", i);
                    break;
                }
                else if(ans[num]==5||make[num]==1){
                    fail=1;
                    break;
                }

                make[num]=1;
                tmp=num;
                num=0;
                while(tmp>0){
                    num+=((tmp%10)*(tmp%10));
                    tmp/=10;
                }
            }

            if(ans[num]==0&&fail==0) printf("%d\n", i);

            for(j=0;j<500;j++){
                if(make[j]==1&&fail==0) ans[j]=1;
                else if(make[j]==1&&fail==1) ans[j]=5;
            }
        }
    }
}
