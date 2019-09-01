#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

int n, ans=0;

void magic(int a, int deep){
    if(deep>n) return;

    for(int i=2;i<a;i++) if(a%i==0) return;

    if(deep==n){
        printf("%d\n", a);
        return;
    }
    for(int i=1;i<=9;i+=2) magic(a*10+i,deep+1);
    return;
}

int main()
{
    scanf("%d", &n);

    for(int i=2;i<10;i++) magic(i,1);
}
