#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans=0;
    string s;

    getline(cin,s);

    while(s[0]==' ') s.erase(s.begin());
    while(s[s.size()-1]==' ') s.pop_back();

    for(int i=0;i<s.size();i++){
        if(s[i]==' ') ans++;
    }

    if(s.empty()) ans=-1;
    printf("%d\n", ans+1);
}
