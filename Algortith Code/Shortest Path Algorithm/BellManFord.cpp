#include <bits/stdc++.h>
using namespace std;

int BellManFord(vector<vector<pair<int, int>>> &g, int vertex, int source, int dest, vector<int> &dist){
    
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < g.size(); i++)
    {
        for (auto &j : g[i])
        {
            edges.push_back({i, {j.first, j.second}});
        }
    }

    dist[source] = 0;

    for(int i=1; i<= vertex - 1; i++){
        for(auto edge: edges){
            int x = edge.first;
            int y = edge.second.first;
            int w = edge.second.second;

            if(dist[x] != INT_MAX and dist[x] + w < dist[y]){
                dist[y] = dist[x] + w;
            }
        }
    }
    
    for(int i=1; i<= vertex - 1; i++){
        for(auto edge: edges){
            int x = edge.first;
            int y = edge.second.first;
            int w = edge.second.second;

            if(dist[x] != INT_MAX and dist[x] + w < dist[y]){
                // negative cycle detected
                return INT_MAX;
            }
        }
    }

    return dist[dest];

}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> g(v);
    vector<int> dist(v, INT_MAX);

    for(int i=0; i<e; i++){
        int x, y, w;
        cin >> x >> y >> w;

        g[x].push_back({y, w});
    }

    int res = BellManFord(g, v, 0, 2, dist);

    if(res == INT_MAX){
        cout << "Negative cycle" << endl;
    }
    else{
        cout << res << endl;
    }

    return 0;
}

/*
4
3
0 1 2
1 2 2
3 3 1

output:
4 [distance between 0 and 2]
*/