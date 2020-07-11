#include <bits/stdc++.h>

using namespace std;

int board[9][9], prt=0;
int row[9][10], col[9][10], sqr[3][3][10];
vector< pair<int,int> > zero;

void solve(int fill_zero){
    if(fill_zero==zero.size()){
        if(!prt){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    printf("%d", board[i][j]);
                }
                printf("\n");
            }
            prt=1;
        }
        return;
    }

    for(int i=1;i<=9;i++){
        if(prt) return;
        if(!row[zero[fill_zero].first][i]&&!col[zero[fill_zero].second][i]&&!sqr[zero[fill_zero].first/3][zero[fill_zero].second/3][i]){
            board[zero[fill_zero].first][zero[fill_zero].second]=i;
            row[zero[fill_zero].first][i]=1;
            col[zero[fill_zero].second][i]=1;
            sqr[zero[fill_zero].first/3][zero[fill_zero].second/3][i]=1;
            solve(fill_zero+1);
            row[zero[fill_zero].first][i]=0;
            col[zero[fill_zero].second][i]=0;
            sqr[zero[fill_zero].first/3][zero[fill_zero].second/3][i]=0;
        }
    }

    return;
}

int main()
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%1d", &board[i][j]);
            if(board[i][j]==0) zero.push_back({i,j});
            else{
                row[i][board[i][j]]=1;
                col[j][board[i][j]]=1;
                sqr[i/3][j/3][board[i][j]]=1;
            }
        }
    }
    solve(0);
}
