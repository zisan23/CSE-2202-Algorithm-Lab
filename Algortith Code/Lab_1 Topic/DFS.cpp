#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){

    visited[v] = true;
    st.push(v);

    for(auto i: adj[v]){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }
    
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


    while(!st.empty()){
        int x = st.top();

        cout << x << " ";

        st.pop();
    }

    return 0;
}