#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int prime[MAXN];

int main()
{
    int test_case, i, j, tmp, fail, pl, ans;
    int check[10], cmp[10];
    char paper[10];

    scanf("%d", &test_case);

    i=2;
    while(i<MAXN){
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    getchar();
    for(i=0;i<test_case;i++){
        gets(paper);

        ans=0;
        for(j=0;j<10;j++) check[j]=0;
        for(j=0;paper[j]!='\0';j++) check[paper[j]-'0']++;

        for(j=2;j<MAXN;j++){
            if(prime[j]==0){
                tmp=j;
                fail=0;
                pl=0;
                for(int k=0;k<10;k++) cmp[k]=check[k];

                while(tmp>0){
                    pl++;
                    tmp/=10;
                }
                if(pl>strlen(paper)) break;

                tmp=j;
                while(tmp>0){
                    if(cmp[tmp%10]>0) cmp[tmp%10]--;
                    else{
                        fail=1;
                        break;
                    }
                    tmp/=10;
                }
                if(fail==0) ans++;
            }
        }

        printf("%d\n", ans);
    }
}
