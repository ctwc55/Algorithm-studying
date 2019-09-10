#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

vector<int> memo;

int binarySearch(int n){
    int s=0, e=memo.size()-1, mid;
    mid=(s+e)/2;
    while(s<e){
        mid=(s+e)/2;
        if(memo[mid]<n) s=mid+1;
        else e=mid;
    }
    return e;
}

int main()
{
    int n, a;

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &a);
        if(memo.empty()||memo.back()<a) memo.push_back(a);
        else memo[binarySearch(a)]=a;
    }

    printf("%d\n", memo.size());
}
