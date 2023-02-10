#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll L, R;
int search(vector<ll>& v, int i){
    ll tar = R / v[i];
    int idx1 = i, idx2 = i, l = i + 1, r = v.size() - 1;
    if(v[i] * v[r] < L || v[i] * v[i + 1] > R)
        return 0;
    while(l <= r){
        ll m = l + (r - l) / 2;
        if(v[m] <= tar){
            l = m + 1;
            idx1 = m;
        }
        else
            r = m - 1;
    }
    tar = ceil((double)L / v[i]), l = i + 1, r = v.size() - 1;
    while(l <= r){
        ll m = l + (r - l) / 2;
        if(v[m] >= tar){
            r = m - 1;
            idx2 = m;
        }
        else
            l = m + 1;
    }
    return idx1 - idx2 + 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll ans = 0;
    cin >> n >> L >> R;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 1; i++)
        ans += search(v, i);
    cout << ans;
    return 0;
}
