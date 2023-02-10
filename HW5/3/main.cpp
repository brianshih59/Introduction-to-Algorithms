#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int find(int i, vector<int>& parent){
    if(parent[i] == i)
        return i;
    parent[i] = find(parent[i], parent);
    return parent[i];
}

void merge(int u, int v, vector<int>& parent, vector<int>& rnk){
    if(rnk[u] == rnk[v])
        rnk[u]++;
    if(rnk[u] > rnk[v])
        parent[v] = u;
    else
        parent[u] = v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, e, w;
    while(cin >> v >> e >> w){
        int ans = 0;
        vector<pair<int, pii>> edges;
        vector<bool> outPost(v, 0);
        for(int i = 0; i < e; i++){
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({c, {a, b}});
        }
        sort(edges.begin(), edges.end());
        for(int i = 0; i < w; i++){
            int j;
            cin >> j;
            outPost[j] = 1;
        }
        vector<int> parent(v), rnk(v, 0);
        for(int i = 0; i < v; i++)
            parent[i] = i;

        // 先連兩邊皆為非outPost的
        for(auto& [w, v]: edges){
            if(outPost[v.first] || outPost[v.second])
                continue;
            int set_i = find(v.first, parent);
            int set_j = find(v.second, parent);
            if(set_i != set_j){
                merge(set_i, set_j, parent, rnk);
                ans += w;
            }
        }

        // 若所有非outPost之間並非connected，則為-1
        int setidx = -1;
        bool flag = 0;
        for(int i = 0; i < v; i++){
            // 找到第一個非outpost
            if(setidx == -1 && !outPost[i]){
                setidx = find(i, parent);
                continue;
            }
            // 看剩下的非outpost是不是跟他在同一個set
            if(!outPost[i] && find(i, parent) != setidx)
                flag = 1;
        }
        if(flag){
            cout << -1 << '\n';
            continue;
        }

        // 將剩下的連起來
        for(auto& [w, v]: edges){
            if(!outPost[v.first] && !outPost[v.second])
                continue;
            int set_i = find(v.first, parent);
            int set_j = find(v.second, parent);
            if(set_i != set_j){
                merge(set_i, set_j, parent, rnk);
                ans += w;
            }
        }

        // 檢查是否都在同一個set
        setidx = find(0, parent);
        flag = 0;
        for(int i = 1; i < v; i++)
            if(find(i, parent) != setidx)
                flag = 1;
        if(!flag)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}
