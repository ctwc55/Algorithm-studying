#include <bits/stdc++.h>
#define MAXN 15000000

using namespace std;

int dr[8]={-1,0,1,-1,1,-1,0,1};
int dw[8]={-1,-1,-1,0,0,1,1,1};

long long int memo[MAXN];

long long int nk(int n, int k){
    if(memo[k]){
        cout<<k<<" : "<<memo[k]<<endl;
        return memo[k];
    }

    memo[k]=1;
    for(int i=1;i<=7-(k%7);i++) memo[k]=(memo[k]*nk(n,k/7))%1000000000;
    for(int i=7-(k%7)+1;i<=7;i++) memo[k]=(memo[k]*nk(n,k/7+1))%1000000000;
    cout<<k<<" : "<<memo[k]<<endl;
    return memo[k];
}

int main()
{
    int n, k, i;
    long long int small=1, ans=1;
    cin>>n>>k;
    for(i=1;i<=7;i++){
        small*=n;
        memo[i]=small;
    }
    if(k<7) ans=memo[k];
    else{
        for(i=1;i<=7-(k%7);i++){
            if(i==7) break;
            ans=(ans*nk(n,k/7))%1000000000;
            cout<<i<<" : "<<ans<<endl;
        }
        for(i=7-(k%7)+1;i<=7;i++){
            if(i==7) break;
            ans=(ans*nk(n,k/7+1))%1000000000;
            cout<<i<<" : "<<ans<<endl;
        }
        if(k%7==0) ans=(ans*nk(n,k/7))%1000000007;
        else ans=(ans*nk(n,k/7+1))%1000000007;
    }
    cout<<ans;
}
