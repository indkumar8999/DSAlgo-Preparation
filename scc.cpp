
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> g, bool visited[], stack<int> &s, int i){
    visited[i] = true;

    for(int j=0;j<g[i].size();j++){
        if(!visited[g[i][j]]){
            dfs(g, visited, s, g[i][j]);
        }
    }
    s.push(i);
}

void dfs_for_scc(vector<vector<int>> g, bool visited[], vector<int> &v, int i){
    visited[i] = true;
    v.push_back(i);
    for(int j=0;j<g[i].size();j++){
        if(!visited[g[i][j]]){
            dfs_for_scc(g, visited, v, g[i][j]);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    vector<vector<int> > g(n, v);
    vector<vector<int> > gt(n, v);
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        gt[y].push_back(x);
    }

    bool visited[n];
    memset(visited, false, sizeof(visited));
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(g, visited, s, i);
        }
    }
    memset(visited, false, sizeof(visited));
    vector<vector<int>> scc;
    while(!s.empty()){
        int x = s.top();
        if(!visited[x]){
            vector<int> vs;
            dfs_for_scc(gt, visited, vs, x);
            scc.push_back(vs);
        }
        s.pop();
    }

    for(int i=0;i<scc.size();i++){
        for(int j=0;j<scc[i].size();j++){
            cout<<scc[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

