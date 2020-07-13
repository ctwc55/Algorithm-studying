#include <bits/stdc++.h>
#define MAXN 1000000000000

using namespace std;

vector<string> words;
vector<char> cap_chk;
map<char,int> cap;
int N, chk[10];

long long int solve(int idx){
    long long int ret=-MAXN;

    if(idx==cap_chk.size()){
        int sum=0, num;
        for(int i=0;i<words.size();i++){
            num=0;
            for(int j=0;j<words[i].size();j++){
                num*=10;
                num+=cap[words[i][j]];
            }
            sum+=num;
        }

        return sum;
    }

    for(int i=0;i<10;i++){
        if(!chk[i]){
            cap[cap_chk[idx]]=i;
            chk[i]=1;
            ret=max(ret,solve(idx+1));
            chk[i]=0;
        }
    }

    return ret;
}

int main()
{
    string input;

    scanf("%d", &N);
    for(int i=0;i<N;i++){
        cin>>input;
        words.push_back(input);
        for(int j=0;j<input.size();j++){
            if(!cap.count(input[j])){
                cap[input[j]]=0;
                cap_chk.push_back(input[j]);
            }
        }
    }

    printf("%lld\n", solve(0));
}
