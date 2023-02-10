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
    if (rnk[u] == rnk[v])
        rnk[u]++;
    if(rnk[u] > rnk[v])
        parent[v] = u;
    else
        parent[u] = v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, e, s;
    while(cin >> v >> e >> s){
        int plan1 = 0;
        vector<pair<int, pii>> edges;
        vector<bool> rumor(v, 0);
        for(int i = 0; i < e; i++){
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({c, {a, b}});
        }
        for(int i = 0; i < s; i++){
            int j;
            cin >> j;
            rumor[j] = 1;
        }
        sort(edges.begin(), edges.end(), greater<pair<int, pii>>());
        vector<int> parent(v), rnk(v, 0);
        for(int i = 0; i < v; i++)
            parent[i] = i;

        int edge = 0;
        for(auto& [w, v]: edges){
            int set_i = find(v.first, parent);
            int set_j = find(v.second, parent);
            if(set_i != set_j){
                merge(set_i, set_j, parent, rnk);
                plan1 += w;
                ++edge;
            }
        }
        // 連不起來
        if(edge < v - 1){
            cout << "no" << '\n';
            continue;
        }

        int plan2 = 0;
        reverse(edges.begin(), edges.end());
        vector<int> parent2(v);
        rnk.assign(v, 0);
        for(int i = 0; i < v; i++)
            parent2[i] = i;

        // 若有一端為rumor，不管是否有cycle皆連起來
        for(auto& [w, v]: edges){
            if(rumor[v.first] || rumor[v.second]){
                int set_i = find(v.first, parent2);
                int set_j = find(v.second, parent2);
                merge(set_i, set_j, parent2, rnk);
                plan2 += w;
            }
        }
        // 將剩下的連起來
        for(auto& [w, v]: edges){
            int set_i = find(v.first, parent2);
            int set_j = find(v.second, parent2);
            if(set_i != set_j){
                merge(set_i, set_j, parent2, rnk);
                plan2 += w;
            }
        }
        // 檢查是否為同個component
        int setidx = find(0, parent2);
        bool flag = 0;
        for(int i = 1; i < v; i++)
            if(find(i, parent2) != setidx)
                flag = 1;
        if(!flag)
            cout << plan1 - plan2;
        else
            cout << "no";
        cout << '\n';
    }
    return 0;
}
