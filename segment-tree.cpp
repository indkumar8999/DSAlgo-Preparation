
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int make_segment_tree(int a[], int st[], int s, int e, int i){
    if(s == e){
        st[i] = a[e];
        return st[i];
    }else{
        int m = s + (e-s)/2;
        st[i] = make_segment_tree(a,st,s,m,2*i+1) + make_segment_tree(a,st,m+1,e,2*i+2);
        return st[i];
    }
}

int get_sum(int st[], int l, int r, int s, int e, int i){
    if(l<=s && r>=e){
        return st[i];
    }
    if(r<s || l>e){
        return 0;
    }
    int m = s +(e-s)/2;
    return get_sum(st, l, r, s, m, 2*i+1) + get_sum(st, l, r, m+1, e, 2*i+2);
}


void update_index(int st[], int index, int diff, int s, int e, int i){
    if(index >= s && index <= e){
        st[i] = st[i] + diff;
        int m = s + (e-s)/2;
        if(s != e){
            update_index(st, index, diff, s, m, 2*i+1);
            update_index(st, index, diff, m+1, e, 2*i+2);
        }
    }
}

int main(){
    int n;
    cin>>n;

    int a[n];
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int st[max_size];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int y = make_segment_tree(a, st, 0, n-1, 0);
    int l = 1, r = 4;
    cout<<get_sum(st,l,r,0,n-1, 0)<<endl;
    int in=3, val=8;
    int diff = val - a[in];
    update_index(st, in, diff, 0, n-1, 0);
    cout<<get_sum(st,l,r,0,n-1, 0)<<endl;

    return 0;
}
