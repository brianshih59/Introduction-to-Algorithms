#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> time;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a < b)
            time.push_back({a, b});
    }
    sort(time.begin(), time.end(), cmp);
    cout << time[0].first << " " << time[0].second << "\n";
    int finish = time[0].second;
    for(int i = 1; i < time.size(); ++i){
        if(time[i].first >= finish){
            cout << time[i].first << " " << time[i].second << "\n";
            finish = time[i].second;
        }
    }
    return 0;
}
