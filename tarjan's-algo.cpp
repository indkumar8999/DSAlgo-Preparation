
#include <bits/stdc++.h>

using namespace std;

static int t = 0;
vector<int> tmp;
vector<vector<int> > ans;

void SCCUtil(vector<vector<int> > g, int n, int u, bool in_stack[], int disc[], int low[], stack<int> &s){
    t++;
    disc[u] = t;
    low[u] = t;

    s.push(u);
    in_stack[u] = true;

    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(disc[v] == -1){
            SCCUtil(g, n, v, in_stack, disc, low, s);
            low[u] = min(low[u], low[v]);
        }else if(in_stack[v]){
            low[u] = min(low[u], disc[v]);
        }
    }
    int w = 0;
    if(low[u] == disc[u]){

        while(s.top() != u){
            w = s.top();
            in_stack[w] = false;
            tmp.push_back(w);
            s.pop();
        }
        w = s.top();
        tmp.push_back(w);
        in_stack[w] = false;
        s.pop();
        ans.push_back(tmp);
        tmp.clear();
    }
}

void SCC(vector<vector<int> > g, int n){
    bool in_stack[n];
    stack<int> s;

    int disc[n];
    int low[n];
    memset(in_stack, false, sizeof(in_stack));
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));

    for(int i=0;i<n;i++){
        if(disc[i] == -1) {
            SCCUtil(g, n, i, in_stack, disc, low, s);
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;

    vector<int> v_tmp;
    vector<vector<int> >g(n, v_tmp);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    SCC(g, n);
    cout<<"----------------------SCC\'s-------------------------\n";
    for(auto x : ans){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"------------------------------------------------------";
    return 0;
}
/*
Input:
5 5
0 1
1 2
2 0
2 3
3 4

Output:
----------------------SCC's-------------------------
4 
3 
2 1 0 
------------------------------------------------------
*/
