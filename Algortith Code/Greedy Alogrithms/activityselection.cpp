#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[i] = {x, y};
    }

    sort(adj.begin(), adj.end(), sortbysec);

    for (int i = 0; i < n; i++)
    {
        cout << i << " ";

        bool found = false;

        for (int j = i + 1; j < n; j++)
        {
            if (adj[j].first >= adj[i].second)
            {
                i = j - 1;
                found = true;
                break;
            }
        }

        if (found == false)
        {
            break;
        }
    }

    return 0;
}