#include <bits/stdc++.h>
using namespace std;

const int N = 25e2 + 10;
vector<int> a(N);
vector<int> dp;
vector<int> subsequence;

int lis(int index)
{
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int ans = 1;
    int subseqIndex = -1;

    for (int i = 0; i < index; i++)
    {
        if (a[i] < a[index])
        {
            int currentLIS = lis(i) + 1;
            if (currentLIS > ans)
            {
                ans = currentLIS;
                subseqIndex = i;
            }
        }
    }
    dp[index] = ans;

    if (subseqIndex != -1)
    {
        subsequence[index] = subseqIndex;
    }

    return ans;
}

// O(N^2)

int main()
{
    int n;
    cin >> n;

    dp.assign(n, -1);
    subsequence.assign(n, -1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = lis(i);
    }

    int lisEndIndex = max_element(dp.begin(), dp.end()) - dp.begin();

    vector<int> lisSequence;

    while (lisEndIndex != -1)
    {
        lisSequence.push_back(a[lisEndIndex]);
        lisEndIndex = subsequence[lisEndIndex];
    }

    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        cout << lisSequence[i];
        if (i < lisSequence.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}