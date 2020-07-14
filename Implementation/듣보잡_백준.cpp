#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string,int> m;
set<string> ans;

int main()
{
    string name;

    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        cin>>name;
        m[name]=0;
    }
    for(int i=0;i<M;i++){
        cin>>name;
        if(m.count(name)) ans.insert(name);
    }

    printf("%d\n", ans.size());
    while(!ans.empty()){
        cout<<*ans.begin()<<"\n";
        ans.erase(ans.begin());
    }
}
