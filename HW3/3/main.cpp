#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> energy;

int fight(int i){
    if(i <= 1)
        return energy[i];
    if(dp[i] != INT_MAX)
        return dp[i];
    dp[i] = energy[i] + min(fight(i - 1), fight(i - 2));
    return dp[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp.assign(n + 1, INT_MAX);
    energy.assign(n + 1, 0);
    for(int i = 0; i < n; ++i)
        cin >> energy[i];
    cout << fight(n);
    return 0;
}
