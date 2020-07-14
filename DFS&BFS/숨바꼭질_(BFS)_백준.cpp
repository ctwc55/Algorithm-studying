#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int N, K, chk[MAXN+1];
queue< pair<int,int> > q;

int solve(){
    q.push({N,0});
    while(!q.empty()){
        if(q.front().first==K) break;
        else if(q.front().first>=0&&q.front().first<=MAXN){
            if(chk[q.front().first]){
                q.pop();
                continue;
            }

            chk[q.front().first]=1;
            if(q.front().first>K) q.push({q.front().first-1,q.front().second+1});
            else{
                q.push({q.front().first+1,q.front().second+1});
                q.push({q.front().first*2,q.front().second+1});
                q.push({q.front().first-1,q.front().second+1});
            }
        }
        q.pop();
    }

    return q.front().second;
}

int main()
{
    scanf("%d %d", &N, &K);

    printf("%d\n", solve());
}
