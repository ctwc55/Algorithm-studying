#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

int heap[100001], heap_size=0;

void minHeap(int n){
    int tmp;
    if(n==1) return;
    if(heap[n/2]>heap[n]&&heap[n/2]!=0){
        tmp=heap[n];
        heap[n]=heap[n/2];
        heap[n/2]=tmp;
        minHeap(n/2);
    }
    return;
}

void rmvRoot(int n){
    int small, small_i, tmp;
    if(n>heap_size/2) return;
    if(heap[(n*2)+1]==0){
        small=heap[n*2];
        small_i=n*2;
    }
    else{
        small=(heap[n*2]<heap[(n*2)+1])?heap[n*2]:heap[(n*2)+1];
        small_i=(heap[n*2]<heap[(n*2)+1])?n*2:(n*2)+1;
    }
    if(heap[n]<small) return;
    tmp=heap[n];
    heap[n]=heap[small_i];
    heap[small_i]=tmp;
    rmvRoot(small_i);
    return;
}

int main()
{
    int n, ord;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &ord);
        if(ord!=0){
            heap[++heap_size]=ord;
            minHeap(heap_size);
        }
        else{
            printf("%d\n", heap[1]);
            if(heap_size>0){
                heap[1]=heap[heap_size];
                heap[heap_size]=0;
                heap_size--;
                rmvRoot(1);
            }
        }
    }
}
