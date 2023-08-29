#include <bits/stdc++.h>
using namespace std;

int main(){
    int v, e;

    cin >> v >> e;

    int g[v][v];

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i==j){
                g[i][j] = 0;
            }
            else{
                g[i][j] = INT_MAX;
            }
        }
    }

    for(int i=0; i<e; i++){
        int x, y, wt;

        cin >> x >> y >> wt;

        g[x][y] = wt;
    }

    // O(v^3)

    for(int k=0; k<v; ++k){
        for(int i=0; i<v; ++i){
            for(int j=0; j<v; ++j){
                if(g[i][k] != INT_MAX and g[k][j] != INT_MAX){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    for(int i=0; i<v; ++i){
        for(int j=0; j<v; ++j){
            if(g[i][j] == INT_MAX){
                cout << "INF ";
            }
            else{
                cout << g[i][j] << " ";
            }
        }
        cout << endl;
    }
}



// For negative cycle

// for (int i = 0; i < V; i++)
//         if (dist[i][i] < 0)
//             return true;
//     return false;