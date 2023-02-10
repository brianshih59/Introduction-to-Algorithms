// maximum bipartite matching

#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

int n, m, c, r;

bool dfs(int x, vector<vi>& adj, vector<vi>& slot, vector<bool>& vis, vi& times){
    for(int y: adj[x]){
        if(!vis[y - m]){    // ����^��
            vis[y - m] = 1;
            if(times[y - m] < c){   // slot �٨S�W�L capacity
                slot[y - m].push_back(x);
                times[y - m]++;
                return 1;
            }
            for(int i: slot[y - m]){    // �� augmenting path
                if(dfs(i, adj, slot, vis, times)){
                    slot[y - m].push_back(x);
                    times[y - m]++;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m >> c >> r){
        vector<vi> adj(n + m);
        for(int i = 0; i < m; i++){
            int a, t;
            cin >> a >> t;
            for(int j = 0; j < t; j++){
                int s;
                cin >> s;
                adj[a].push_back(s + m);
                adj[s + m].push_back(a);
            }
        }
        for(int i = 0; i < r; i++){
            vector<vi> slot(n); // �s��U�� slot matching ����H
            vi times(n, c); // �O���U�� slot �s�F�X�ӹ�H
            int u;
            cin >> u;
            for(int j = 0; j < u; j++){
                int x;
                cin >> x;
                times[x] = 0;
            }
            int matching = 0;
            for(int i = 0; i < m; i++){
                vector<bool> vis(n, 0);
                if(dfs(i, adj, slot, vis, times))
                    ++matching;
            }
            cout << m - matching << '\n';
        }
    }
    return 0;
}
