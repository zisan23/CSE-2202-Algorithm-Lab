#include <bits/stdc++.h>
using namespace std;

// O(2^m*n)
int lcs(string a, string b, int m, int n){

    if(m==0 or n==0) {
        return 0;
    }
    if(a[n-1] == b[n-1]){
        return 1+lcs(a, b, m-1, n-1);
    }
    else {
        return max(lcs(a, b, m-1, n), lcs(a, b, m, n-1));
    }
}

int lcs_mem(string a, string b, int m, int n, vector<vector<int>> &mem){
    if(m==0 or n ==0) {
        return 0;
    }
    if(a[m-1] == b[n-1]) {
        return mem[m][n] = 1 + lcs_mem(a, b, m-1, n-1, mem);
    }
    if(mem[m][n] != -1) {
        return mem[m][n];
    }
    return mem[m][n] = max(lcs_mem(a, b, m-1, n, mem), lcs_mem(a, b, m, n-1, mem));
}

int lcs_dp(string a, string b, int m, int n, vector<vector<int>> &dp){

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 or j==0) {
                dp[i][j] = 0;
            }
            else if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}



void print_lcs_dp(string a, string b, int m, int n, vector<vector<int>> &dp) {
    int p = dp[m][n];

    char lcsi[p+1];
    lcsi[p] = '\0';

    int i=m, j=n;

    while (i>0 and j>0)
    {
        if(a[i-1] == b[j-1]){
            lcsi[p-1] = a[i-1];
            i--;
            j--;
            p--;
        }

        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << lcsi << endl;
}
int main() {
    string a, b;
    cin >> a >> b;

    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    int ans = lcs_dp(a, b, m, n, dp);
    
    cout << ans << endl;

    print_lcs_dp(a, b, m, n, dp);

    return 0;
}