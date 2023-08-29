#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
    visited[v] = true;

    for(auto i: adj[v]){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }

    st.push(v);
}

void dfs2(int v, int count, vector<vector<int>> &transpose, vector<bool> &visited, vector<int> &teamplate){
    visited[v] = true;

    for(auto i:transpose[v]){
        if(!visited[i]){
            dfs2(i, count, transpose, visited, teamplate);
        }
    }

    teamplate.push_back(v);
}

int main(){
    int v, e; cin >> v >> e;

    vector<vector<int>> adj(v);

    for(int i=0; i<e; i++){
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
    }

    vector<bool> visited(v, false);
    stack<int> st;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }

    vector<vector<int>> transpose(v);

    vector<vector<int>> teamplate;
    

    // transpose list
    for(int i=0; i<v; i++){
        visited[i] = false;
        for(auto j: adj[i]){
            transpose[j].push_back(i);
        }
    }

    int count = 0;

    while(!st.empty()){
        int temp = st.top();
        st.pop();

        if(!visited[temp]){
            vector<int> component;
            count++;
            dfs2(temp, count, transpose, visited, component);
            teamplate.push_back(component);
        }
    }

    cout << count << endl;

    for(const auto &component: teamplate){
        for(int node:component){
            cout << node+1 << " ";
        }
        cout << endl;
    }

    return 0;
}