#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st){
    visited[v] = 1;

    for(int i: adj[v]){
        if(visited[i] == 0){
            if(dfs(i, adj, visited, st)){
                return true;
            }
        }
        else if(visited[i] == 1){
            return true;
        }
    }

    visited[v] = 2;
    st.push(v);

    return false;
}


void topologicalSort(int numberofvertex, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st, vector<int> &result){
    
    for(int i=0; i<numberofvertex; i++){
        if(visited[i] == 0){
            if(dfs(i, adj, visited, st)){
                return;
            }
        }
    }

    int a = 0;
    while(!st.empty()){
        result[a] = st.top();
        a++;
        st.pop();
    }
    return;
}

int main(){
    int v, e; cin >> v >> e;

    vector<vector<int>> adj(v);

    for(int i=0; i<e; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    vector<int> visited(v, 0);
    vector<int> result(v);
    stack<int> st;

    topologicalSort(v, adj, visited, st, result);

    if(result.empty()){
        cout << "Cycle Exists" << endl;
    }
    else{
        
        for(int i: result){
            cout << i << " ";
        }

        cout << endl;
    }
    return 0;
}