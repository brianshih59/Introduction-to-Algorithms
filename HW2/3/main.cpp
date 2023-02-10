#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll findMinMove(vector<int> v){
    int n = v.size();
    ll steps = 0;
    nth_element(v.begin(), v.begin() + n / 2, v.end());
    int median = v[n / 2];
    for(int i = 0; i < n; i++)
        steps += (ll)abs(v[i] - median);
    return steps;
}

ll partition(vector<int>& v){
    if(v.size() <= 2)
        return 0;
    int mid = (v.size() + 1) / 2;
    vector<int> a(v.begin(), v.begin() + mid), b(v.begin() + mid, v.end());
    ll x = findMinMove(a);
    ll y = findMinMove(b);
    return min(x + partition(b), y + partition(a));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << partition(v);
    return 0;
}
