#include <bits/stdc++.h>
using namespace std;

list<int> path;

void dfs(int start, vector<vector<int>> &adj, vector<int> &out){
    while(out[start] != 0){
        int next = adj[start][--out[start]];

        dfs(next, adj, out);
    }
    path.emplace_front(start);
}

int findstartnode(int v, vector<vector<int>> &adj, vector<int> &in, vector<int> &out){
    int start = 0;

    for(int i=0; i<v; i++){
        if(out[i] - in[i] == 1){
            return i;
        }

        if(out[i]  > 0){
            start = i;
        }
    }

    return start;
}

void countInOutDegree(int v, vector<vector<int>> &adj, vector<int> &in, vector<int> &out){
    for(int i=0; i<v; i++){
        for(auto j: adj[i]){
            out[i]++;
            in[j]++;
        }
    }
}

bool isEuler(int v, vector<vector<int>> &adj, vector<int> &in, vector<int> &out){
    int start_node = 0;
    int end_node = 0;

    for(int i=0; i<v; i++){
        if((in[i] - out[i]) > 1 or (out[i] - in[i]) > 1){
            return false;
        }
        else if(out[i] - in[i] == 1){
            start_node++;
        }
        else if(in[i] - out[i] == 1){
            end_node++;
        }
    }

    if((end_node == 0 and start_node == 0) or (end_node == 1 and start_node == 1)){
        return true;
    }
    else{
        return false;
    }
}

void findEulerianPath(int v, int e, vector<vector<int>> &adj, vector<int> &in, vector<int> &out){
    countInOutDegree(v, adj, in, out);

    if(!isEuler(v, adj, in, out)){
        cout << "Not Euler" << endl;
        return;
    }

    dfs(findstartnode(v, adj, in, out), adj, out);

    return;
}

int main(){
    int v, e;

    cin >> v >> e;

    vector<vector<int>> adj(v);

    for(int i=0; i<e; i++){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    vector<int> in(v, 0);
    vector<int> out(v, 0);

    findEulerianPath(v, e, adj, in, out);

    if (path.size() == e + 1)
    {
        while (path.size()>1)
        {
            cout << path.front() << "->";
            path.pop_front();
        }
        cout<<path.front()<< endl;
    }
    else
    {
        cout << "No Eulerian Path/Circuit exists" << endl;
    }

    return 0;
}