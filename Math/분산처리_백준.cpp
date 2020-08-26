#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, a, b, data;

    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d", &a, &b);
        data=1;
        for(int j=0;j<b;j++) data=(data*a)%10;
        printf("%d\n", data==0?10:data);
    }
}
