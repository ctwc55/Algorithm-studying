#include <bits/stdc++.h>

using namespace std;

int N, K;
string num;

string solve(){
    string ans;

    for(int i=0;i<N;i++){
        while(!ans.empty()&&ans[ans.size()-1]-'0'<num[i]-'0'){
            if(ans.size()+N-i==N-K){
                ans+=num.substr(i,N-i);
                break;
            }
            ans.pop_back();
        }
        if(ans.size()==N-K) break;
        ans+=num[i];
    }

    return ans;
}

int main()
{
    scanf("%d %d", &N, &K);
    cin>>num;

    cout<<solve()<<"\n";
}
