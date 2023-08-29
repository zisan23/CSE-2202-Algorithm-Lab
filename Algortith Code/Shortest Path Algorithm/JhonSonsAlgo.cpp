#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int result[10000][10000];

void bellmanFord(vector<vector<int>> &graph, int source, vector<int> &distances) {
    int V = graph.size();
    distances[source] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] != INF && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }
    }
}

void dijkstra(vector<vector<int>> &graph, int source, vector<int> &distances) {
    int V = graph.size();
    vector<bool> visited(V, false);
    distances[source] = 0;

    for (int i = 0; i < V; ++i) {
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!visited[j] && (u == -1 || distances[j] < distances[u])) {
                u = j;
            }
        }

        if (distances[u] == INF) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] != INF && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
}

void johnsonsAlgorithm(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> h(V, 0); // Heuristic values for Bellman-Ford

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            result[i][j] = INT_MAX;
        }
    }

    // Perform Bellman-Ford algorithm to find heuristic values
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF) {
                h[v] = min(h[v], h[u] + graph[u][v]);
            }
        }
    }

    // Create a modified graph with updated edge weights
    vector<vector<int>> modifiedGraph(V, vector<int>(V, INF));
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF) {
                modifiedGraph[u][v] = graph[u][v] + h[u] - h[v];
            }
        }
    }

    // Run Dijkstra's algorithm for all vertices
    for (int source = 0; source < V; ++source) {
        vector<int> distances(V, INF);
        dijkstra(modifiedGraph, source, distances);

        // Adjust the distances with heuristic values
        for (int v = 0; v < V; ++v) {
            if (distances[v] != INF) {
                distances[v] = distances[v] - h[source] + h[v];
            }
        }
        
        for (int v = 0; v < V; ++v) {
            //cout << "Vertex " << v << ": " << distances[v] << endl;
            result[source][v] = distances[v];
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>(V, INF));

    for (int i = 0; i < V; ++i) {
        graph[i][i] = 0; // Self-loop distance is 0
    }

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    johnsonsAlgorithm(graph);

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(result[i][j] == INT_MAX){
                cout << "INF ";
            }
            else{
                cout << result[i][j] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}
/*

//main jhonsons
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int result[10000][10000];

bool flag = false; // to detect negetive cycle

void bellmanFord(vector<vector<int>> &graph, int source, vector<int> &distances) {
    int V = graph.size();
    distances[source] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] != INF && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }
    }

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] != INF && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                    flag = true;
                }
            }
        }
    }
}

void dijkstra(vector<vector<int>> &graph, int source, vector<int> &distances) {
    int V = graph.size();
    vector<bool> visited(V, false);
    distances[source] = 0;

    for (int i = 0; i < V; ++i) {
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!visited[j] && (u == -1 || distances[j] < distances[u])) {
                u = j;
            }
        }

        if (distances[u] == INF) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] != INF && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
}

void johnsonsAlgorithm(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> h(V, 0);

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            result[i][j] = INT_MAX;
        }
    }
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF) {
                h[v] = min(h[v], h[u] + graph[u][v]);
            }
        }
    }
    vector<vector<int>> modifiedGraph(V, vector<int>(V, INF));
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != INF) {
                modifiedGraph[u][v] = graph[u][v] + h[u] - h[v];
            }
        }
    }
    for (int source = 0; source < V; ++source) {
        vector<int> distances(V, INF);
        dijkstra(modifiedGraph, source, distances);

        for (int v = 0; v < V; ++v) {
            if (distances[v] != INF) {
                distances[v] = distances[v] - h[source] + h[v];
            }
        }
        
        for (int v = 0; v < V; ++v) {
            //cout << "Vertex " << v << ": " << distances[v] << endl;
            result[source][v] = distances[v];
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v, vector<int>(v, INF));

    for(int i=0; i<v; ++i){
        graph[i][i] = 0;
    }

    for(int i=0; i<e; ++i){
        int x, y, wt;

        cin >> x >> y >> wt;
        graph[x][y] = wt;
    }

    johnsonsAlgorithm(graph);

    if(flag == true){
        cout << "not possible" << endl;
        return 0;
    }

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i == j){
                continue;
            }
            cout << i << " to " << j << ": ";

            if(result[i][j] == INT_MAX){
                cout << "infinity" << endl;
            }
            else{
                cout << result[i][j] << endl;
            }
        }
    }

}*/
