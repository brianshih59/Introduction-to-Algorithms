#include <bits/stdc++.h>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, pii>> cost;
    int cnt = 0, ans = 0;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a == b){
            ++cnt;
            ans += a;
        }
        else
            cost.push_back({abs(a - b), {a, b}});
    }
    sort(cost.begin(), cost.end(), greater<pair<int, pii>>());
    int firstHalf = 0, secondHalf = 0;
    for(auto& [f, s]: cost){
        if(cnt == n)
            break;
        if(s.F > s.S){
            if(secondHalf < n / 2){
                ans += s.S;
                ++secondHalf;
            }
            else{
                ans += s.F;
                ++firstHalf;
            }
        }
        else{
            if(firstHalf < n / 2){
                ans += s.F;
                ++firstHalf;
            }
            else{
                ans += s.S;
                ++secondHalf;
            }
        }
        ++cnt;
    }
    cout << ans;
    return 0;
}
