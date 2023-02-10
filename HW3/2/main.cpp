#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i)
        cin >> coins[i];
    int Q;
    cin >> Q;
    vector<ll> total(Q);
    for(int i = 0; i < Q; ++i){
        cin >> total[i];
        for(int j = 0; j < n; ++j){
            ll cnt;
            cin >> cnt;
            total[i] -= cnt * coins[j];
        }
        total[i] = llabs(total[i]);
    }
    sort(coins.begin(), coins.end());
    int k = *max_element(total.begin(), total.end());
    vector<int> dp(k + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= k; ++i){
        for(int coin: coins){
            if(i - coin < 0)
                break;
            if(dp[i - coin] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    for(int i: total)
        cout << dp[i] << "\n";
    return 0;
}
