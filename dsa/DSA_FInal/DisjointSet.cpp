#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    int node;
    int *parent;
    int *rank;
    int *size;

    void makeset(){
        for(int i=1; i<=node; i++){
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }

public:
    DisjointSet(int value){
        this->node = value;
        parent = new int[value+1];
        rank = new int[value+1];;
        size = new int[value+1];

        makeset();
    }

    int find(int x){
        
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionByRank(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY]){
                swap(rootX, rootY);
            }

            parent[rootY] = rootX;

            if (rank[rootX] == rank[rootY]){
                rank[rootX]++;
            }
        }
    }
};

int main(){
    DisjointSet d = DisjointSet(6);

    d.unionByRank(1, 2);
    d.unionByRank(2, 3);
    d.unionByRank(4, 5);
    //d.unionByRank(1, 5);

    for(int i=1; i<6; i++){
        cout << d.find(i) << " ";
    }

    cout << endl;
    return 0;
}