#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> population, inorder, postorder, mp;

class Treenode{
public:
    int val;
    Treenode *left, *right;
    Treenode(int x) : val(x), left(NULL), right(NULL){}
};

Treenode* build(int start, int end, int& postIdx){
    if(start > end)
        return NULL;
    Treenode* root = new Treenode(postorder[postIdx--]);
    int inIdx = mp[root->val];
    root->right = build(inIdx + 1, end, postIdx);
    if(root->right && population[root->right->val] > population[root->val])
        ans++;
    root->left = build(start, inIdx - 1, postIdx);
    if(root->left && population[root->left->val] > population[root->val])
        ans++;
    return root;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    population.resize(n + 1);
    inorder.resize(n + 1);
    postorder.resize(n + 1);
    mp.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> population[i];
    for(int i = 1; i <= n; i++){
        cin >> inorder[i];
        mp[inorder[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        cin >> postorder[i];
    int postIdx = n;
    build(1, n, postIdx);
    cout << ans;
    return 0;
}
