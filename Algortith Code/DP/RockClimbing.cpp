#include <bits/stdc++.h>
using namespace std;

int rc(vector<vector<int>> &a, int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = a[i][j] + 0;
            }
            else
            {
                // if(j==1) {
                //     dp[i][j] = dp[i][j] + min(a[i-1][j], a[i-1][j+1]);
                // }
                // else if(j==m) {
                //     dp[i][j] = dp[i][j] + min(a[i-1][j-1], a[i-1][j]);
                // }
                // else {
                //     dp[i][j] = dp[i][j] + min({a[i-1][j-1], a[i-1][j], a[i-1][j+1]});
                // }

                if (j - 1 < 0)
                {
                    dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                }
                else if (j >= 1 and j + 1 <= n - 1)
                {
                    dp[i][j] = a[i][j] + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]});
                }
                else
                {
                    dp[i][j] = a[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }
    }

    int minimum = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minimum = min(minimum, dp[m - 1][i]);
    }
    return minimum;
}

void print(vector<vector<int>> &a, int m, int n, vector<vector<int>> &dp) {
    //cout << "x" << endl;
    vector<int> path;
    int p, q;
    for(int i=m-1; i>0; i--){
        int temp = INT_MAX;
        //cout << "x" << endl;
        for(int j=0; j<n; j++){
            if(temp <= dp[i][j]){
                continue;
            }
            else {
                temp = dp[i][j];
                p = i;
                q = j;
            }
        }
        path.push_back(a[p][q]);
    }
    int x;
    if(q+1 > n-1){
        x = min({a[p-1][q-1], a[p-1][q]});
    }
    else if(q-1 < 0){
        x = min({a[p-1][q], a[p-1][q+1]});
    }
    else{
        x = min({a[p-1][q-1], a[p-1][q], a[p-1][q+1]});
    }
    path.push_back(x);

    for(auto i: path) {
        cout << i << " ";
    }
    cout << endl;

}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int ans = rc(a, m, n, dp);
    cout << ans << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "|||||||||||||\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    print(a, m, n, dp);

    return 0;
}

// #include <bits/stdc++.h>
// #include <algorithm>
// using namespace std;

// const int N = 100, val = 1e5;
// int n, m;
// int a[N][N], c[N][N], dp[N];

// void printBest(int i, int j)
// {

//     if (i == 0 || j == 0 || j == m + 1)
//     {
//         return;
//     }

//     if ((a[i - 1][j - 1] <= a[i - 1][j]) && (a[i - 1][j - 1] <= a[i - 1][j + 1]))
//     {
//         printBest(i - 1, j - 1);
//     }

//     else if ((a[i - 1][j] <= a[i - 1][j - 1]) && (a[i - 1][j] <= a[i - 1][j + 1]))
//     {
//         printBest(i - 1, j);
//     }

//     else if ((a[i - 1][j + 1] <= a[i - 1][j - 1]) && (a[i - 1][j + 1] <= a[i - 1][j]))
//     {
//         printBest(i - 1, j + 1);
//     }

//     cout << i << " " << j << endl;
// }

// int main()
// {

//     cout << "Enter the row and col of the array : " << endl;
//     cin >> n >> m;

//     cout << "Enter the array : " << endl;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             cin >> c[i][j];
//         }
//     }

//     for (int i = 1; i < m; i++)
//     {
//         a[0][i] = 0;
//     }

//     for (int i = 0; i <= n + 1; i++)
//     {
//         a[i][0] = val;
//         a[i][m + 1] = val;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {

//             if (i == 1)
//             {
//                 a[i][j] = c[i][j];
//             }

//             else
//             {
//                 a[i][j] = c[i][j] + min(min(a[i - 1][j - 1], a[i - 1][j]), a[i - 1][j + 1]);
//             }
//         }
//     }

//     for (int i = 1; i <= m; i++)
//     {
//         dp[i - 1] = a[n][i];
//     }

//     cout << "Least Total Danger : " << *min_element(dp, dp + m) << endl;
//     printBest(n, min_element(dp, dp + m) - dp + 1);
//     cout << min_element(dp, dp + m) - dp + 1<< endl;
// }