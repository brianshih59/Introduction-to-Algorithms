#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

void dijkstra(vector<vector<pii>>& adj, vector<int>& rad, vector<bool>& shelter, int src, int n){
    vector<int> dis(n, INT_MAX);
    dis[src] = rad[src];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dis[src], src});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto& [v, w]: adj[u]){
            if(dis[u] + w + rad[v] < dis[v]){
                dis[v] = dis[u] + w + rad[v];
                pq.push({dis[v], v});
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++)
        if(shelter[i] && dis[i] < ans)
            ans = dis[i];
    if(ans != INT_MAX)
        cout << ans;
    else
        cout << -1;
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l, r, s;
    while(cin >> l >> r >> s){
        vector<int> rad(l);
        vector<vector<pii>> adj(l);
        vector<bool> shelter(l, 0);
        for(int i = 0; i < l; i++)
            cin >> rad[i];
        for(int i = 0; i < r; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        for(int i = 0; i < s; i++){
            int x;
            cin >> x;
            shelter[x] = 1;
        }
        int src;
        cin >> src;
        dijkstra(adj, rad, shelter, src, l);
    }
    return 0;
}
