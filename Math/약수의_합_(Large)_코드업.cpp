#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int dr[8]={-1,0,1,-1,1,-1,0,1};
int dw[8]={-1,-1,-1,0,0,1,1,1};

int main()
{
    int n;
    double sum=0;
    scanf("%d", &n);
    for(int i=1;i*i<=n;i++){
        if(i*i==n) sum+=i;
        else if(n%i==0){
            sum+=i;
            sum+=n/i;
        }
    }
    printf("%.lf\n", sum);
}
