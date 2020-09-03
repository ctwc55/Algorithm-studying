#include <bits/stdc++.h>

using namespace std;

string s, ans;

string solve(){
    int idx=0;
    while(idx<s.size()){
        if(idx<=s.size()-4&&s.compare(idx,4,"PPAP")==0){
            ans.push_back('P');
            idx+=4;
        }
        else{
            ans.push_back(s[idx]);
            idx++;
        }

        if(ans.size()>=4&&ans[ans.size()-4]=='P'&&ans[ans.size()-3]=='P'&&ans[ans.size()-2]=='A'&&ans[ans.size()-1]=='P'){
            for(int i=0;i<4;i++) ans.pop_back();
            ans.push_back('P');
        }
    }

    if(ans.size()==1&&ans[0]=='P') ans.pop_back();

    if(ans.empty()) return "PPAP";
    return "NP";
}

int main()
{
    cin>>s;

    cout<<solve()<<"\n";
}
