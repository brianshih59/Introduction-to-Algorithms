#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> bonus(n);
    for(int i = 0; i < n; ++i)
        cin >> bonus[i];
    int ans = 0, begin = 0, end = 0;
    while(end < n - 1){
        ans++;
        int farthest = end + 1;
        for(int i = begin; i <= end; ++i){
            if(i + bonus[i] >= n - 1){
                cout << ans;
                return 0;
            }
            farthest = max(farthest, i + bonus[i]);
        }
        begin = end + 1;
        end = farthest;
    }
    return 0;
}
