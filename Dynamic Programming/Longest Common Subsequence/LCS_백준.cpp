#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

string a, b;
int d[MAXN+1][MAXN+1];

int solve(){
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }

    return d[a.size()][b.size()];
}

int main()
{
    cin>>a>>b;

    printf("%d\n", solve());
}
