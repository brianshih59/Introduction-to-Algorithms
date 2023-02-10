#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        int l, r;
        cin >> l >> r;
        vector<vector<char>> grid(l, vector<char>(l));
        for(int i = 0; i < l; ++i)
            for(int j = 0; j < l; ++j)
                cin >> grid[i][j];
        int c = l / 2, ans = 0;
        for(int i = c - r; i <= c + r; ++i){
            for(int j = c - r; j <= c + r; ++j){
                if(grid[i][j] == '^')
                    continue;
                int tmp = 0;
                stack<pii> neighbor;
                neighbor.push({i, j});
                while(!neighbor.empty()){
                    pii cur = neighbor.top();
                    neighbor.pop();
                    if(cur.first >= 0 && cur.first < l && cur.second >= 0 && cur.second < l && grid[cur.first][cur.second] == '_'){
                        ++tmp;
                        neighbor.push({cur.first - 1, cur.second});
                        neighbor.push({cur.first + 1, cur.second});
                        neighbor.push({cur.first, cur.second - 1});
                        neighbor.push({cur.first, cur.second + 1});
                        grid[cur.first][cur.second] = '^';
                    }
                }
                ans = max(ans, tmp);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
