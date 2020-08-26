#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A[10], B, win_a=0, win_b=0;

    for(int i=0;i<10;i++) scanf("%d", &A[i]);
    for(int i=0;i<10;i++){
        scanf("%d", &B);
        if(A[i]>B) win_a++;
        else if(A[i]<B) win_b++;
    }

    if(win_a>win_b) printf("A\n");
    else if(win_a<win_b) printf("B\n");
    else printf("D\n");
}
