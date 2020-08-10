#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> parent;

void init(){
    for(int i=1;i<=n;i++) parent[i]=i;

    return;
}

int find_parent(int x){
    if(x==parent[x]) return x;

    return parent[x]=find_parent(parent[x]);
}

void merge(int a, int b){
    a=find_parent(a);
    b=find_parent(b);

    parent[b]=a;

    return;
}

int main() {
    int c, a, b;
    
    scanf("%d %d", &n, &m);
    parent.resize(n+1);
    init();
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &c, &a, &b);
        if(c==0) merge(a,b);
        else{
            if(find_parent(a)==find_parent(b)) printf("YES\n");
            else printf("NO\n");
        }
    }
}
