#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> length(n);
    for(int i = 0; i < n; ++i)
        cin >> length[i];
    int ans = 0;
    for(int len: length){
        if(!ans || length[ans - 1] < len)
            length[ans++] = len;
        else{
            auto it = lower_bound(length.begin(), length.begin() + ans, len);
            length[it - length.begin()] = len;
        }
    }
    cout << ans;
    return 0;
}
