#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long ans = 1, m = 1e9 + 7;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        if(v[i] > n)
            ans *= (n - i);
        else if(v[i] - i < 1){
            ans = 0;
            break;
        }
        else
            ans *= (v[i] - i);
        ans %= m;
    }
    cout << ans;
    return 0;
}
