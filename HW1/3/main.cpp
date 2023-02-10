#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
vector<int> cur;
void sum(const vector<int>& v, long long tar, int start){
    if(tar == 0 && cur.size() == 4){
        ++ans;
        return;
    }
    if((cur.size() == 4 && tar != 0) || start >= n)
        return;
    for(int i=start; i<n && v[i] <= tar; ++i){
        if(i == start || v[i] != v[i-1]){
            cur.push_back(v[i]);
            sum(v, tar - v[i], i + 1);
            cur.pop_back();
        }
    }
}
int main(){
    long long t;
    cin >> n >> t;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    sum(v, t, 0);
    if(ans)
        cout << ans;
    else
        cout << "FeiDooDoo_Zuo_Wei_Men";
    return 0;
}
