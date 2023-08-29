#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int dist, indx;

    node()
    {
        dist = 0;
        indx = -1;
    }

    node(int dist, int indx)
    {
        this->dist = dist;
        this->indx = indx;
    }
};

class PriorityQueue
{
public:
    node *arr;
    int size;
    int capacity;

    PriorityQueue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        arr = new node[capacity];
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }
    int left_child(int index)
    {
        return (2 * index + 1);
    }
    int right_child(int index)
    {
        return (2 * index + 2);
    }

    void Heapify(int index)
    {
        int l = left_child(index);
        int r = right_child(index);

        int lowest = index;

        if (l < size and arr[l].dist < arr[lowest].dist)
        {
            lowest = l;
        }
        if (r < size and arr[r].dist < arr[lowest].dist)
        {
            lowest = r;
        }

        if (lowest != index)
        {
            swap(arr[lowest], arr[index]);
            Heapify(lowest);
        }
    }

    int Size(){
        return size;
    }

    void push(int value, int index)
    {
        if (size == capacity)
        {
            return;
        }

        arr[size] = node(value, index);

        size++;

        for (int i = 0; i < size; i++)
        {
            Heapify(i);
        }
    }

    node extractMin()
    {

        if (size == 0)
            return node();

        node temp = arr[0];

        swap(arr[0], arr[size - 1]);
        size--;

        Heapify(0);

        return temp;
    }

    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void pop(){
        if(size == 0){
            return;
        }
        if(size == 1){
            size--;
            return;
        }
        node root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        Heapify(0);
        return;
    }
};

void dijkstra(vector<vector<pair<int, int>>> &g, int source, int vertex, vector<int> &dist)
{
    
    vector<bool> vis(vertex, false);

    PriorityQueue q = PriorityQueue(vertex*vertex+vertex);

    //set<pair<int, int>> st;

    q.push(0, source);
    dist[source] = 0;

    while(q.Size() > 0){
        auto min_element = q.extractMin();
        int v = min_element.indx;
        int distance = min_element.dist;
        
       // q.pop();

        if(vis[v] == true){
            continue;
        }

        vis[v] = true;

        for(auto child: g[v]){
            int child_v =  child.first;
            int wt = child.second;

            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                q.push(dist[child_v], child_v);
            }
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> g(v);
    vector<int> dist(v, INT_MAX);

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        g[x].push_back({y, w});
    }

    dijkstra(g, 0, v, dist); // source = 0

//printing all the shortest path from the source
    for(int i=0; i<v; i++){
        if(dist[i] == INT_MAX){
            cout << i << ": -1" << endl; // if no path present then print -1
            continue;
        }
        cout << i << ": " << dist[i] << endl;
    }

    return 0;
}