
#include <bits/stdc++.h>

using namespace std;


int get_sum(int bit[], int i){
    int sum = 0;
    i = i+1;
    while(i > 0){
        sum += bit[i];
        i = i - (i&-i);
    }
    return sum;
}

void update_bit(int bit[], int n, int i, int x){
    i = i+1;

    while(i <= n){
        bit[i] += x;
        i = i + (i&-i);
    }
}

void construct_bit(int bit[], int a[], int n){
    for(int i=1;i<=n;i++){
        bit[i] = 0;
    }
    for(int i=0;i<n;i++){
        update_bit(bit, n, i, a[i]);
    }
}

int main(){

    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int bit[n+1];
    construct_bit(bit, a, n);
    
    int i;
    cin>>i;
    cout<<get_sum(bit, i);

    return 0;
}
