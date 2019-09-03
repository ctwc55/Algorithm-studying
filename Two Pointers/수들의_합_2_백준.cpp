#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

int num[10000];

int main()
{
    int n, m, s=-1, e=-1, sum=0, ans=0;

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &num[i]);

    while(e<n){
        if(sum<m) sum+=num[++e];
        else if(sum==m){
            ans++;
            sum+=num[++e];
            sum-=num[++s];
        }
        else sum-=num[++s];
    }

    printf("%d\n", ans);
}
