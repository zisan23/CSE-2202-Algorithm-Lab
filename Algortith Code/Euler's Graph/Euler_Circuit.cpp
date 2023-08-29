#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited){
    visited[v] = true;

    for(auto i: adj[v]){
        if(!visited[i]){
            dfs(i, adj, visited);
        }
    }
}

bool isConnected(int v, vector<vector<int>> &adj, vector<bool> &visited){
    
    int i;
    
    for(i=0; i<v; i++){
        if(adj[i].size() != 0){
            break;
        }
    }

    if(i == v){
        return true;
    }

    dfs(0, adj, visited);

    for(int i=0; i<v; i++){
        if(visited[i] == false and adj[i].size() > 0){
            return false;
        }
    }
    return true;
}

int isEuler(int v, vector<vector<int>> &adj, vector<bool> &visited){
    if(isConnected(v, adj, visited) == false){
        return 0;
    }

    int odd = 0;

    for(int i=0; i<v; i++){
        if(adj[i].size() & 1){
            odd++;
        }
    }

    if(odd > 2){
        return 0; // not euler
    }

    else if(odd == 2){
        return 1;
    }
    else if(odd == 0){
        return 2;
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

    int res = isEuler(v, adj, visited);

    if(res == 0){
        cout << "not euler" << endl;
    }
    else if(res == 1){
        cout << "euler path" << endl;
    }
    else if(res == 2){
        cout << "euler circuit" << endl;
    }

    return 0;
}