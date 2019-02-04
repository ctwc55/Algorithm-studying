#include <bits/stdc++.h>
#define MAXN 15000000

using namespace std;

int dr[8]={-1,0,1,-1,1,-1,0,1};
int dw[8]={-1,-1,-1,0,0,1,1,1};

int main()
{
    string com;
    cin>>com;
    for(int i=0;com[i]!='\0';i++){
        if(com[i]=='H'){
            printf("Hello, world! ");
        }
        else if(com[i]=='Q'){
            cout<<com<<" ";
        }
        else if(com[i]=='9'){
            printf("99 bottles of beer on the wall, 99 bottles of beer. \n");
            for(int j=98;j>=2;j--){
                printf("Take one down and pass it around, %d bottles of beer on the wall. \n",j);
                printf("%d bottles of beer on the wall, %d bottles of beer. \n",j,j);
            }
            printf("Take one down and pass it around, 1 bottle of beer on the wall. \n");
            printf("1 bottle of beer on the wall, 1 bottle of beer. \n");
            printf("Take one down and pass it around, no more bottles of beer on the wall. \n");
            printf("No more bottles of beer on the wall, no more bottles of beer. \n");
            printf("Go to the store and buy some more, 99 bottles of beer on the wall. ");
        }
    }
}
