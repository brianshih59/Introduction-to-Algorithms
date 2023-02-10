#include <bits/stdc++.h>
using namespace std;

bool cmp(string& s1, string& s2){
    return s1 + s2 > s2 + s1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string ans;
    int n;
    cin >> n;
    vector<string> cards(n);
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        cards[i] = to_string(num);
    }
    sort(cards.begin(), cards.end(), cmp);
    for(auto s: cards)
        ans += s;
    if(ans[0] == '0')
        cout << 0;
    else
        cout << ans;
    return 0;
}
