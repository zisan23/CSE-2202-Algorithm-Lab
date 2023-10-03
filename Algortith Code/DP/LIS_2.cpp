#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

int lis(vector <int> &a) {
    int n = a.size();

    for(int i=0; i<n; i++) {
        auto itr = lower_bound(ans.begin(), ans.end(), a[i]);

        if(itr == ans.end()) {
            ans.push_back(a[i]);
        }
        else {
            *itr = a[i];
        }
    }
    return ans.size();
}

// O(nlogn)

int main() {
    int n;
    cin >> n;

    vector <int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int res = lis(a);

    cout << res << endl;
     
    for (int i=0; i<res; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}