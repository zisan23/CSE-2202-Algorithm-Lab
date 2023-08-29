#include <bits/stdc++.h>
using namespace std;


class DSU{
    int* parent;
    int* rank;

public:
    DSU(int size){
        parent = new int[size];
        rank = new int[size];
    }

    void make_set(int size){
        for(int i=0; i<size; i++){
            parent[i] = i;
            rank[i]= 1;
        }
    }

    int find(int value){
        if(parent[value] == value){
            return value;
        }

        return parent[value] = find(parent[value]);
    }

    void Union(int data1, int data2){
        int set1 = find(data1);
        int set2 = find(data2);


        if(set1 != set2){
            if(rank[set1] < rank[set2]){
                parent[set1] = set2;
            }
            else if(rank[set1] > rank[set2]){
                parent[set2] = set1;
            }
            else{
                parent[set2] = set1;
                rank[set1]++;
            }
        }
    }
};

// path in pair
// int kruskal(vector<pair<int, pair<int, int>>> &adj, int v, vector<pair<int, int>> &path){

//path in matrix
int kruskal(vector<pair<int, pair<int, int>>> &adj, int v, vector<vector<int>> &path){
    sort(adj.begin(), adj.end());

    

    DSU set(v);
    set.make_set(v);
    
    int totalCost = 0;

    for(auto it: adj){
        int wt = it.first;
        int n = it.second.first;
        int m = it.second.second;

        if(set.find(n) != set.find(m)){
            set.Union(n, m);
            totalCost += wt;

            path[n][m] = 1;
            path[m][n] = 1;

        }
    }

    return totalCost;
}


int main(){

    int v, e;
    cin >> v >> e;

    vector<pair<int, pair<int, int>>> adj;
    //vector<pair<int, int>> path;

    vector<vector<int>> path(v, vector<int>(v, 0));

    for(int i=0; i<e; i++){
        int x, y, wt;

        cin >> x >> y >> wt;

        adj.push_back( {wt, {x, y}});
    }

    // int minCost = kruskal(adj, v, path);

    int minCost = kruskal(adj, v, path);

    cout << "MINIMUM COST: " << minCost << endl;

    //print path in pair

    // for(int i=0; i<path.size(); i++){
    //     cout << path[i].first << " -> " << path[i].second << endl;
    // }

    //check matrix

    // for(int i=0; i<path.size(); i++){
    //     for(int j=0; j<path.size(); j++){
    //         cout << path[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //print matrix

    for(int i=0; i<path.size(); i++){
        for(int j=0; j<path.size(); j++){
            if(i < j and path[i][j]){
                cout << i << " -> " << j << endl;
            }
        }
    }


    return 0;

}





