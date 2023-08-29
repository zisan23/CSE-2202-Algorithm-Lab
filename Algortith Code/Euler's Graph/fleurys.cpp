#include<bits/stdc++.h>
using namespace std;

int dfscount(int p, vector<vector<int>> &adj, vector<bool> &visited){
    visited[p] = true;
    int count = 1;

    for(auto i: adj[p]){
        if(i!= -1 and !visited[i]){
            count += dfscount(i, adj, visited);
        }
    }
    return count;
}

void removeedge(int u, int v, vector<vector<int>> &adj){
    auto iu = find(adj[u].begin(), adj[u].end(), v);
    auto iv = find(adj[v].begin(), adj[v].end(), u);

    if(iu != adj[u].end()){
        *iu = -1;
    }

    if(iv != adj[v].end()){
        *iv = -1;
    }
}

bool isNotBridge(int V, int u, int v, vector<vector<int>> &adj, vector<bool> &visited){
    int count = 0;

    for(auto i: adj[u]){
        if(i != -1){
            count++;
        }
    }

    if(count == 1){
        return true;
    }

    visited.assign(V, false);

    int dfs_count = dfscount(u, adj, visited);

    if(dfs_count == 1){
        return false;
    }

    removeedge(u, v, adj);

    visited.assign(V, false);

    int dfs_count2 = dfscount(u, adj, visited);

    adj[u].push_back(v);
    adj[v].push_back(u);

    if(dfs_count > dfs_count2){
        return false;
    }
    else{
        return true;
    }
}

void eulerUtil(int V, int u, vector< vector<int>> &adj, vector<bool> &visited){
    for(auto i: adj[u]){
        if(i != -1 and isNotBridge(V, u, i, adj, visited)){
            cout << u << "-" << i << " ";
            removeedge(u, i, adj);
            eulerUtil(V, i, adj, visited);
        }
    }
}

void isEuler(int V, vector<vector<int>> &adj, vector<bool> &visited){
    int u = -1;
    int count = 0;

    for(int i=0; i<adj.size(); i++){
        if(adj[i].size() & 1){
            if(u == -1){
                u = i;
            }
            count++;
        }
    }

    if(u == -1){
        u = 0;
    }

    if(count == 0 or count == 2){
        eulerUtil(V, u, adj, visited);
        cout << endl;
    }
    else{
        cout << "No euler path\n";
    }
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);
    vector<bool> visited(v, false);

    for(int i=0; i<e; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    isEuler(v, adj, visited);

    return 0;

}