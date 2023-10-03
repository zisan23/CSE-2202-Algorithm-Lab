#include<bits/stdc++.h>
using namespace std;

//int options[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };

int options[] = { 5,  20, 30}; //<- problematic for taka = 40

map<int,int> Coin_change(int rem_taka){

    int n = sizeof(options)/sizeof(options[0]);

    map<int,int> coin_freq;

    for(int i=0; i<n; i++){
        coin_freq[options[i]] = 0;
    }

    int count = 0;
        
        for(int i=n-1; i>=0; i--){

            if(rem_taka>=options[i]){
                int div = rem_taka/options[i];
                rem_taka = rem_taka%options[i];

                if(rem_taka<0) rem_taka += options[i];

                coin_freq[options[i]] += div;
                count += div;

                if(rem_taka==0) break;
            }
        }
    
    cout<<count<<endl;

    return coin_freq;

}

int main(){

    int taka;

    cin>>taka;

    
    map<int,int> coins = Coin_change(taka);


return 0;
}