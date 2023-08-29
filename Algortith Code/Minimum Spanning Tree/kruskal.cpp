#include <bits/stdc++.h>
using namespace std;

class DSU {
    int* parent;
    int* rank;
 
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
 
    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

void kruskal(int v, vector<vector<int>> &adj){
    sort(adj.begin(), adj.end());

    DSU s(v);

    int ans = 0;

    for(auto i: adj){
        int w = i[0];
        int x = i[1];
        int y = i[2];

        if(s.find(x) != s.find(y)){
            s.unite(x, y);
            ans += w;

            cout << x << "--" << y << "==" << w << endl;
        }
    }

    cout << "Min cost: " << ans;
}

int main(){
    int v, e;

    cin >> v >> e;

    vector<vector<int>> adj(e);

    for(int i=0; i<e; i++){
        int x, y, w;
        cin >> x >> y >> w;

        adj[i] = {w, x, y};
    }

    kruskal(v, adj);

    return 0;
}