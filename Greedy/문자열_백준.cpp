#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

int main()
{
    char A[55], B[55];
    int min_same=MAXN, cnt;

    scanf("%s %s", A, B);

    for(int i=0;i<=strlen(B)-strlen(A);i++){
        cnt=0;
        for(int j=0;j<strlen(A);j++){
            if(A[j]!=B[i+j]) cnt++;
        }
        min_same=min(min_same,cnt);
    }

    printf("%d\n", min_same);
}
