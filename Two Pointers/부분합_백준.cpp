#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

int num[100000];

int main()
{
    int n, m, s=-1, e=-1, sum=0, ans=MAXN;

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &num[i]);

    while(e<n){
        if(sum<m) sum+=num[++e];
        else {
            while(sum>=m) sum-=num[++s];
            ans=min(ans,e-s+1);
        }
    }

    if(ans==MAXN) printf("0\n");
    else printf("%d\n", ans);
}
