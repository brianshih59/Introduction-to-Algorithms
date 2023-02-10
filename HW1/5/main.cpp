#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll accu(vector<ll>& v, int j){
    ll ans = 0;
    for(int i=0; i<j; i++)
        ans += v[i];
    return ans;
}
int main(){
    ll n;
    int k, j = 0;
    cin >> n >> k;
    if(n < k){
        cout << "NO";
        return 0;
    }
    vector<ll> v(k, 1);
    ll sum = n, total = n;
    for(int i=60; i>=0; i--){
        ll num = 1;
        num <<= i;
        n = sum;
        if(n < num)
            continue;
        while(n >= num){
            n -= num;
            v[j] = num;
            j++;
        }
        if(j < k){
            if(count(v.begin() + j, v.end(), 1) >= n){
                ll ac = accu(v, k);
                while(ac > total){
                    v[--j] = 1;
                    ac -= (num - 1);
                }
                if(ac == total){
                    cout << "YES" << endl;
                    for(ll i: v)
                        cout << i << " ";
                    return 0;
                }
            }
            if(j > 0)
                sum = total - accu(v, j);
        }
        else{
            if(accu(v, k) == total){
                cout << "YES" << endl;
                for(ll i: v)
                    cout << i << " ";
                return 0;
            }
            else
                break;
        }
    }
    cout << "NO";
    return 0;
}
