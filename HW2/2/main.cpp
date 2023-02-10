#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        mp[num]++;
    }
    vector<pair<int, int>> v;
    for(auto[f, s]: mp)
        v.push_back({s, f});
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    cout << v[k - 1].second;
    return 0;
}
