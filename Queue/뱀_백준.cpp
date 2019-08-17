#include <bits/stdc++.h>

using namespace std;

queue< pair<int,int> > mov;
queue< pair<int,char> > order;
int board[105][105]; //snake-1 apple-5

int main()
{
    int N, K, L, appX, appY, time=1;
    int headX=1, headY=1, dir=1; // U-0 R-1 D-2 L-3
    pair<int,char> data;
    pair<int,int> tail;

    scanf("%d", &N);
    scanf("%d", &K);
    for(int i=0;i<K;i++){
        scanf("%d %d", &appX, &appY);
        board[appX][appY]=5;
    }
    scanf("%d", &L);
    for(int i=0;i<L;i++){
        scanf("%d %c", &data.first, &data.second);
        order.push(data);
    }

    board[1][1]=1;
    tail.first=1;
    tail.second=1;
    mov.push(tail);
    headY++;

    while(1){
        if(headX<1 || headX>N || headY<1 || headY>N) break;
        if(board[headX][headY]==1) break;

        if(board[headX][headY]==0){
            board[mov.front().first][mov.front().second]=0;
            mov.pop();
        }
        board[headX][headY]=1;
        tail.first=headX;
        tail.second=headY;
        mov.push(tail);
        time++;

        if(order.size()>0){
            if(time-1==order.front().first){
                if(order.front().second=='L') dir=(dir+3)%4;
                else dir=(dir+1)%4;
                order.pop();
            }
        }

        if(dir==0) headX--;
        else if(dir==1) headY++;
        else if(dir==2) headX++;
        else headY--;
    }

    printf("%d\n", time);
}