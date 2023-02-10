#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int mod = 1e8 + 7;
    int m, n;
    cin >> m >> n;
    vector<int> cur(n, 1);
    for(int i = 1; i < m; i++)
        for(int j = 1; j < n; j++){
            cur[j] += cur[j - 1];
            cur[j] %= mod;
        }
    cout << cur[n - 1];
    return 0;
}
