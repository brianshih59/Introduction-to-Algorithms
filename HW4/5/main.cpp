#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; ++i)
        cin >> prices[i];
    prices.push_back(0);
    sort(prices.begin(), prices.end());
    int k;
    cin >> k;
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        if(prices[i] == prices[i - 1])
            continue;
        if(prices[i] - prices[i - 1] - 1 <= k){
            ans += (ll)prices[i] * (prices[i] + 1) / 2 - (ll)prices[i - 1] * (prices[i - 1] + 1) / 2 - prices[i];
            k -= prices[i] - prices[i - 1] - 1;
        }
        else{
            ans += (ll)(prices[i - 1] + k) * (prices[i - 1] + k + 1) / 2 - (ll)prices[i - 1] * (prices[i - 1] + 1) / 2;
            k = 0;
            break;
        }
    }
    if(k)
        ans += (ll)(prices.back() + k) * (prices.back() + k + 1) / 2 - (ll)prices.back() * (prices.back() + 1) / 2;
    cout << ans;
    return 0;
}
