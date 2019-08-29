#include <bits/stdc++.h>

using namespace std;

int r, c, cnt=0, cplt=0;
int set_cnt;

void z(int n, int m, int d, int ans){
    cnt+=set_cnt;

    cout<<n<<" "<<m<<" "<<set_cnt<<endl;

    if(n==r+1&&m==c+1){
        cplt=1;
        return;
    }

    if(r+1<=n && c+1<=m) z(n-d, m-d, d>>1, cnt);
    else if(r+1<=n && c+1<=m){
        set_cnt=d*d*2;
        z(n-d, m, d>>1, cnt);
    }
    else if(r+1<=n && c+1<=m){
        set_cnt=d*d*2;
        z(n, m-d, d>>1, cnt);
    }
    else{
        set_cnt=d*d*3;
        z(n, m, d>>1, cnt);
    }
}

int main()
{
    int N, box;

    scanf("%d %d %d", &N, &r, &c);
    box=1<<N;

    if(r+1<=box>>1 && c+1<=box>>1) z(box>>1, box>>1, box>>2, cnt);
    else if(r+1<=box>>1 && c+1<=box){
        set_cnt=(box>>1)*(box>>1);
        z(box>>1, box, box>>2, cnt);
    }
    else if(r+1<=box && c+1<=box>>1){
        set_cnt=(box>>1)*(box>>1)*2;
        z(box, box>>1, box>>2, cnt);
    }
    else{
        set_cnt=(box>>1)*(box>>1)*3;
        z(box, box, box>>2, cnt);
    }

    printf("%d\n", cnt);
}
