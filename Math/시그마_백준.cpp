#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long A, B;

    scanf("%lld %lld", &A, &B);

    printf("%lld\n", (A+B)%2==0?(A+B)/2*(abs(A-B)+1):(A+B)*((abs(A-B)+1)/2));
}
