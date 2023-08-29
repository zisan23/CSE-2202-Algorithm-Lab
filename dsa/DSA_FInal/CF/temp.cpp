#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int n, m;

    while(t--){
        cin >> n >> m;
        ll a[n], b[m];

        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
        }

        int j = 0, k = 0, x, y, f = n, g = m;

        while(1){
            x = a[j];
            y = b[k];

            if(x-y <= 0){
                f--;
                j++;
            } else{
                cout << "c" << endl;
                a[j] = x - y;
            }
            if(y-x <= 0){
                g--;
                k++;
            } else{
                cout << "d" << endl;
                b[k] = y - x;
            }

            if(j >=n and k >= m){
                break;
            }
            
        }
        cout << f << "  " << g << endl;
    
        if(f > 0){
            //cout << j << endl;
            cout << "Tsondu" << endl;
        }
        else if(g > 0){
        // cout << k << endl;
            cout << "Tenzing" << endl;
        }
        else if(f == 0 and j == 0){
        // cout << j << " " << k << endl;
            cout << "Draw" << endl;
        }
        
    }
    return 0;
}