
#include <bits/stdc++.h>
using namespace std;

int root(int parent[], int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void union_1(int parent[], int rank[], int x, int y){
    int r_x = root(parent, x);
    int r_y = root(parent, y);
    if(r_x == r_y){
        return;
    }

    if(rank[r_x] >= rank[r_y]){
        parent[r_y] = r_x;
        rank[r_x] += rank[r_y];
    }else{
        parent[r_x] = r_y;
        rank[r_y] += rank[r_x];
    }
}

bool find(int parent[], int x, int y){
    int r_x = root(parent, x);
    int r_y = root(parent, y);
    return r_x == r_y;
}


int main(){

    int n;
    cin>>n;
    int parent[n];
    int rank[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 1;
    }

    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        union_1(parent, rank, x, y);
    }

    cout<<find(parent,0,2)<<"\n";
    cout<<find(parent,1,2)<<"\n";
    cout<<find(parent,3,4)<<"\n";
    cout<<find(parent,3,6)<<"\n";
    cout<<find(parent,6,4)<<"\n";
    cout<<find(parent,0,4)<<"\n";

    return 0;
}
/*
7
6
 0 1
 1 2
 3 4
 4 5
 5 6
 3 6
 */
