#include <bits/stdc++.h>
#define MAXN 1000000000

using namespace std;

typedef struct{
    char result[20];
} OJ;

OJ dom[100000];
OJ kat[100000];

bool cmp(OJ a, OJ b){
    if(strcmp(a.result,b.result)<0) return true;
    else return false;
}

int main()
{
    int n, i, j, turn, ans=0;
    char tmp[20];
    scanf("%d", &n);
    getchar();
    for(i=0;i<n;i++) gets(dom[i].result);
    for(i=0;i<n;i++) gets(kat[i].result);

    sort(dom,dom+n,cmp);
    sort(kat,kat+n,cmp);

    i=0;
    j=0;
    while(1){
        if(i>=n||j>=n) break;

        if(strcmp(dom[i].result,kat[j].result)<=0) turn=0;
        else turn=1;

        if(turn==1){
            strcpy(tmp,dom[i].result);
            while(strcmp(dom[i].result,kat[j].result)>0&&j<n) j++;
        }
        else{
            strcpy(tmp,kat[j].result);
            while(strcmp(dom[i].result,kat[j].result)<0&&i<n) i++;
        }

        while(!strcmp(dom[i].result,kat[j].result)&&i<n&&j<n){
            i++;
            j++;
            ans++;
        }
        while(!strcmp(dom[i].result,tmp)&&i<n) i++;
        while(!strcmp(kat[j].result,tmp)&&j<n) j++;
    }

    printf("%d\n", ans);
}
