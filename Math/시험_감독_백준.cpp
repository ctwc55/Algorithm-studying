#include <bits/stdc++.h>

using namespace std;

int people[1000000];

int main()
{
    int N, B, C;
    long long int ans=0;

    scanf("%d", &N);
    for(int i=0;i<N;i++) scanf("%d", &people[i]);
    scanf("%d %d", &B, &C);

    ans+=N;
    for(int i=0;i<N;i++){
        people[i]-=B;
        if(people[i]>0){
            ans+=(people[i]/C);
            if(people[i]%C>0) ans+=1;
        }
    }

    printf("%lld\n", ans);
}