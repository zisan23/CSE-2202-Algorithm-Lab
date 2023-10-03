#include <bits/stdc++.h>
using namespace std;

vector<int> obj;

// O(2^N)

int knapsack_recursion(int W, vector<int> &w, vector<int> &value, int n)
{
    if (n == 0 or W == 0)
    {
        return 0;
    }

    if (w[n - 1] > W)
    {
        return knapsack_recursion(W, w, value, n - 1);
    }

    else
    {
        return max(value[n - 1] + knapsack_recursion(W - w[n - 1], w, value, n - 1), knapsack_recursion(W, w, value, n - 1));
    }
}

// O(N * W)

int knapsack_dp(int W, vector<int> &w, vector<int> &value, int n)
{
    vector<vector<int>> k(n + 1, vector<int>(W + 1));
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 or j == 0)
            {
                k[i][j] = 0;
            }
            else if (w[i - 1] <= j)
            {
                k[i][j] = max(value[i - 1] + k[i - 1][j - w[i - 1]], k[i - 1][j]);
            }
            else
            {
                k[i][j] = k[i - 1][j];
            }
        }
    }

    // print

    int p = W;
    int res = k[n][W];

    for (i = n; i > 0 and res > 0; i--)
    {
        if (res == k[i - 1][p])
        {
            continue;
        }
        else
        {
            obj.push_back(w[i - 1] - 1);
            res = res - value[i - 1];
            p = p - w[i - 1];
        }
    }

    return k[n][W];
}

int knapsack_spaceoptimized(int W, int wt[], int val[], int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = W; w >= 0; w--)
        {
            if (wt[i - 1] <= w) {
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[W];
}

int main()
{
    vector<int> value = {0, 1, 2, 5, 6};
    vector<int> w = {0, 2, 3, 4, 5};
    int W = 8;
    int n = value.size();

    int ans = knapsack_dp(W, w, value, n);

    cout << ans << endl;

    for (auto i : obj)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}