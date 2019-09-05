#include <bits/stdc++.h>
#define MAXN 10001

using namespace std;

int num[MAXN];

int main()
{
    int n, a;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a);
        num[a]++;
    }

    for(int i=1;i<MAXN;i++) while(num[i]--) printf("%d\n", i);
}
