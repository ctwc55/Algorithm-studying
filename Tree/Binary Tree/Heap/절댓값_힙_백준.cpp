#include <bits/stdc++.h>
#define MAXN 100000000

using namespace std;

pair<int,int> heap[100001]; //first:org second:abs
int heap_size=0;

void absMinHeap(int n){
    if(n==1) return;
    if(heap[n/2].second>heap[n].second&&heap[n/2].second!=0) swap(heap[n/2], heap[n]);
    else if(heap[n/2].second==heap[n].second){
        if(heap[n/2].first>heap[n].first) swap(heap[n/2], heap[n]);
    }
    absMinHeap(n/2);
    return;
}

void rmvRoot(int n){
    int small, small_i;
    if(n>heap_size/2) return;
    if(heap[(n*2)+1].second==0){
        small=heap[n*2].second;
        small_i=n*2;
    }
    else{
        if(heap[n*2].second==heap[(n*2)+1].second){
            small=(heap[n*2].first<heap[(n*2)+1].first)?heap[n*2].second:heap[(n*2)+1].second;
            small_i=(heap[n*2].first<heap[(n*2)+1].first)?n*2:(n*2)+1;
        }
        else{
            small=(heap[n*2].second<heap[(n*2)+1].second)?heap[n*2].second:heap[(n*2)+1].second;
            small_i=(heap[n*2].second<heap[(n*2)+1].second)?n*2:(n*2)+1;
        }
    }
    if(heap[n].second<small) return;
    else if(heap[n].second>small){
        swap(heap[n], heap[small_i]);
        rmvRoot(small_i);
    }
    else if(heap[n].second==small){
        if(heap[n].first>heap[small_i].first){
            swap(heap[n], heap[small_i]);
            rmvRoot(small_i);
        }
    }
    return;
}

int main()
{
    int n, ord;

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &ord);
        if(ord!=0){
            heap[++heap_size].first=ord;
            heap[heap_size].second=abs(ord);
            absMinHeap(heap_size);
        }
        else{
            printf("%d\n", heap[1].first);
            if(heap_size>0){
                heap[1].first=heap[heap_size].first;
                heap[1].second=heap[heap_size].second;
                heap[heap_size].first=0;
                heap[heap_size].second=0;
                heap_size--;
                rmvRoot(1);
            }
        }
    }
}
