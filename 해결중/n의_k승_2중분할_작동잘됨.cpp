#include <bits/stdc++.h>
#define MAXN 200000000

using namespace std;

int dr[8]={-1,0,1,-1,1,-1,0,1};
int dw[8]={-1,-1,-1,0,0,1,1,1};

long long int memo[MAXN];

long long int nk(int n, int k){
    if(k==1||memo[k]) return memo[k];

    if(k%2==0) memo[k]=(nk(n,k/2)*nk(n,k/2))%1000000007;
    else if(k%2==1) memo[k]=(nk(n,k/2)*nk(n,k/2+1))%1000000007;
}

int main()
{
    int n,k;
    cin>>n>>k;
    memo[1]=n;
    nk(n,k);
    cout<<memo[k];
}