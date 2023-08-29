#include <bits/stdc++.h>
using namespace std;

int bridge = 0;


void dfs(int v, vector<vector<int>> &adj, vector<int> &disc, vector<bool> &visited, vector<int> &low, int parent, int &time){
    
    visited[v] = true;
    disc[v] = low[v] = ++time;

    for(auto i:adj[v]){
        if(i == parent){
            continue;
        }

        if(visited[i]){
            low[v] = min(low[v], disc[i]);
        }
        else{
            dfs(i, adj, disc, visited, low, v, time);


            low[v] = min(low[v], low[i]);

            if(low[i] > disc[v]){
                cout << v << " " << i << endl;
                bridge++;
            }
        }
    }
}


void Bridge(int v, vector<vector<int>> &adj){
    vector<int> disc(v, -1);
    vector<bool> visited(v, false);
    vector<int> low(v, -1);

    int parent = -1;
    int time = 0;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, adj, disc, visited, low, parent, time);
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

    Bridge(v, adj);

    cout << bridge << endl;

    return 0;
}