#include <bits/stdc++.h>
#define MAXN 10000000

using namespace std;

int prime[MAXN];
int card[100], card_tmp[100];

vector<int> only_prime;
vector< vector< pair<int,int> > > board; //f:prime factor s:cnt
vector< pair<int,int> > score_calc;

bool primeFactorChk(int n, int p){
    for(int i=0;i<n;i++) if(card[i]%p==0) return true;
    return false;
}

int main()
{
    int n, i, j, prime_cnt=0, factor_disp, tmp;
    int score=1, game_cnt=0;
    vector< pair<int,int> > cont;
    pair<int,int> calc;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &card[i]);
        card_tmp[i]=card[i];
    }

    i=2;
    while(i<MAXN){
        only_prime.push_back(i);
        for(j=i*2;j<MAXN;j+=i) prime[j]=1;
        i++;
        while(prime[i]==1&&i<MAXN) i++;
    }

    for(i=0;i<only_prime.size();i++){
        if(primeFactorChk(n,only_prime[i])){
            prime_cnt++;
            for(j=0;j<n;j++){
                calc.first=only_prime[i];
                calc.second=0;
                while(card[j]%only_prime[i]==0){
                    card[j]/=only_prime[i];
                    calc.second++;
                }
                cont.push_back(calc);
            }
            board.push_back(cont);
            cont.clear();
        }
    }

    for(i=0;i<prime_cnt;i++){
        factor_disp=0;
        for(j=0;j<n;j++) factor_disp+=board[i][j].second;

        if(factor_disp/n<1) continue;

        for(j=0;j<n;j++) calc.first=board[i][j].first;
        calc.second=factor_disp/n;
        score_calc.push_back(calc);
        for(j=0;j<n;j++){
            if(board[i][j].second<calc.second) game_cnt+=(calc.second-board[i][j].second);
        }
    }

    for(i=0;i<score_calc.size();i++){
        tmp=1;
        for(j=0;j<score_calc[i].second;j++) tmp*=score_calc[i].first;
        score*=tmp;
    }

    printf("%d %d\n", score, game_cnt);
}
