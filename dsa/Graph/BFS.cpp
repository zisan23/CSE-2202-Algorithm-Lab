// implementation of bfs 
#include<bits/stdc++.h>
using namespace std;


void bfs(int p, int adj[][1000],int visited[],int len[])
{
    queue<int>q;
    q.push(p);
    visited[p]=1;
    len[p]=0;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        
        for(auto i:adj[p])
        {
            if(!visited[i])
            {
                visited[i]=1;
                len[i]=len[f]+1;
                q.push(i);
            }
        }
    }
}