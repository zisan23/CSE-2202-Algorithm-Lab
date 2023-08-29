#include <bits/stdc++.h>
using namespace std;

void dfs(int p, int adj[][1000], int visited[])
{
    if (!visited[p]) visited[p] = 1;

    for (auto i : adj[p])
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
        }
    }
}

int main(){

    
    return 0;
}