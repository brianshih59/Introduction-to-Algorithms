#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string str;
    getline(cin, str);
    stack<ll> s;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '+'){
            ll a = s.top(); s.pop();
            ll b = s.top(); s.pop();
            s.push(a + b);
            i++;
        }
        else if(str[i] == '*'){
            ll a = s.top(); s.pop();
            ll b = s.top(); s.pop();
            s.push(a * b);
            i++;
        }
        else{
            ll num = 0;
            while(str[i] != ' '){
                num = num * 10 + str[i] - '0';
                i++;
            }
            s.push(num);
        }
    }
    ll x = 1e9 + 7;
    cout << s.top() % x << endl;
    return 0;
}
