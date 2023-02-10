#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> revenue(n);
    for(int i = 0; i < n; i++)
        cin >> revenue[i];
    int mprev = 0, Mprev = 0, m = INT_MAX, M = INT_MIN;
    for(int i = 0; i < n; i++){
        mprev = min(mprev + revenue[i], revenue[i]);
        m = min(m, mprev);
        Mprev = max(Mprev + revenue[i], revenue[i]);
        M = max(M, Mprev);
    }
    m = abs(m);
    cout << max(m, M);
    return 0;
}
