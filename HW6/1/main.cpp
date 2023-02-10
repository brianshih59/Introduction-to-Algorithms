#include <bits/stdc++.h>
using namespace std;

int bfs(int src, vector<int>& dis, vector<bool>& vis, vector<vector<int>>& adj){
    queue<int> q;
    q.push(src);
    int localmax = INT_MIN;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i: adj[x]){
            if(!vis[i]){
                vis[i] = 1;
                dis[i] = dis[x] + 1;
                q.push(i);
            }
        }
        localmax = max(localmax, dis[x]);
    }
    for(auto i: vis)
        if(!i)
            return -1;
    return localmax;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int e;
    while(cin >> e){
        map<pair<string, int>, vector<pair<string, int>>> tmp;
        unordered_map<string, int> mp; // 將點以整數表示
        int idx = 0;
        for(int i = 0; i < e; i++){
            string a, b;
            cin >> a >> b;
            // 出現新的點
            if(mp.find(a) == mp.end())
                mp[a] = idx++;
            if(mp.find(b) == mp.end())
                mp[b] = idx++;

            tmp[{a, mp[a]}].push_back({b, mp[b]});
            tmp[{b, mp[b]}].push_back({a, mp[a]});
        }
        int n = mp.size();
        vector<vector<int>> adj(n);
        for(auto& [si, v]: tmp)
            for(auto& si2: v)
                adj[si.second].push_back(si2.second);
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            vector<int> dis(n, 0);
            vector<bool> vis(n, 0);
            vis[i] = 1;
            int cur = bfs(i, dis, vis, adj);
            if(cur == -1){
                ans = -1;
                break;
            }
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}
