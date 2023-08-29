#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to initialize and return a new adjacency list
vector<vector<pair<int, int>>> initializeGraph(int V) {
    vector<vector<pair<int, int>>> graph(V);
    return graph;
}

// Function to add an edge to the graph
void addEdge(vector<vector<pair<int, int>>>& graph, int src, int dest, int weight) {
    graph[src].push_back(make_pair(dest, weight));
    graph[dest].push_back(make_pair(src, weight));
}

// Eager Prim's algorithm to find the Minimum Spanning Tree (MST)
void eagerPrimMST(vector<vector<pair<int, int>>>& graph) {
    int V = graph.size();
    vector<int> key(V, INT_MAX); // Key values used to pick minimum weight edge
    vector<int> mst(V, -1); // Parent array to store MST
    vector<bool> visited(V, false); // To represent if a vertex is in MST or not

    // Create a priority queue (min heap) to store edges
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with vertex 0
    key[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        // Extract minimum key vertex
        int u = pq.top().second;
        pq.pop();

        visited[u] = true; // Include the vertex in MST

        // Check adjacent vertices of u
        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && weight < key[v]) {
                // Update key value and parent
                key[v] = weight;
                mst[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the Minimum Spanning Tree (MST) edges
    cout << "Minimum Spanning Tree (MST) using Eager Prim's algorithm:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << mst[i] << " -- " << i << " : " << key[i] << endl;
        totalWeight += key[i];
    }

    cout << "Total weight of the Minimum Spanning Tree (MST): " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Create the adjacency list for the graph
    vector<vector<pair<int, int>>> graph = initializeGraph(V);

    // Get input for each edge
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " source, destination, and weight: ";
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }

    // Apply Eager Prim's algorithm to find the MST
    eagerPrimMST(graph);

    return 0;
}