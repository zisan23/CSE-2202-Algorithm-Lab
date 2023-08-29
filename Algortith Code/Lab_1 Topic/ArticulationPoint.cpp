#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, int &time, int par, vector<bool> &isAP){
    int children = 0;

    visited[v] = true;

    disc[v] = low[v] = ++time;

    for(auto i:adj[v]){
        if(!visited[i]){
            children++;
            dfs(i, adj, visited, disc, low, time, v, isAP);

            low[v] = min(low[v], low[i]); // confusion

            if(par != -1 and low[i] >= disc[v]){
                isAP[v] = true;
            }
        }
        else if(i != par){
            low[v] = min(low[v], disc[i]);
        }
    }

    if(par = -1 and children > 1){
        isAP[v] = true;
    }
}

void ArticulatioPoint(int v, vector<vector<int>> &adj){ // v = number of vertices
    vector<int> disc(v, 0);
    vector<int> low(v, 0);
    vector<bool> visited(v, false);
    vector<bool> isAP(v, false);
    
    int time = 0, par = -1;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, adj, visited, disc, low, time, par, isAP);
        }
    }

    for(int i=0; i<v; i++){
        if(isAP[i] == true){
            cout << i << " ";
        }
    }
}


int main(){
    int v, e; cin >> v >> e;

    vector<vector<int>> adj(v);
    

    for(int i=0; i<e; i++){
        int x, y; cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ArticulatioPoint(v, adj);

    cout << endl;

    return 0;
}