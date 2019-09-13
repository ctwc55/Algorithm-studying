#include <bits/stdc++.h>
#define MAXN 100000
#define INF 1000000001

using namespace std;

int num[20], ans=0;

void subsequence(int n, int s, int sum, int deep){
    if(n==deep){
        if(s==sum) ans++;
        return;
    }
    subsequence(n,s,sum+num[deep],deep+1);
    subsequence(n,s,sum,deep+1);
    return;
}

int main()
{
    int n, s;

    scanf("%d %d", &n, &s);
    for(int i=0;i<n;i++) scanf("%d", &num[i]);

    subsequence(n,s,0,0);
    if(s==0) ans--;
    printf("%d\n", ans);
}
