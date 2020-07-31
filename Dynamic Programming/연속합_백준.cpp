#include <bits/stdc++.h>
#define INF 2000000000

using namespace std;

int main()
{
    int n, a, d=-INF, ans=-INF;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        d=max(d+a,a);
        ans=max(ans,d);
    }

    printf("%d\n", ans);
}
