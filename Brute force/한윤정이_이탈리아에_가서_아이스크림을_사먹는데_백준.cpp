#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int bad[201][201];

int main()
{
    int n, m, a, b, ans=0;

    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        bad[a][b]=1;
        bad[b][a]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(bad[i][j]==0&&bad[j][k]==0&&bad[k][i]==0) ans++;
            }
        }
    }

    printf("%d\n", ans);
}
