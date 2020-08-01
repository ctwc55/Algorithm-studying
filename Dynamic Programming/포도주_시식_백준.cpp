#include <bits/stdc++.h>
#define Max(a,b,c) max(max(a,b),c)

using namespace std;

int n;
vector<int> wine, d;

int solve(){
    for(int i=1;i<=n;i++){
        if(i==1) d[i]=wine[i];
        else if(i==2) d[i]=d[i-1]+wine[i];
        else d[i]=Max(d[i-3]+wine[i-1]+wine[i],d[i-2]+wine[i],d[i-1]);
    }

    return d[n];
}

int main()
{
    scanf("%d", &n);
    wine.resize(n+1,0);
    d.resize(n+1,0);
    for(int i=1;i<=n;i++) scanf("%d", &wine[i]);

    printf("%d\n", solve());
}
