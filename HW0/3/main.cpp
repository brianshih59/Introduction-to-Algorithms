#include <bits/stdc++.h>
using namespace std;
int a[1001], c[10001];
double b[1001];
double tax(int salary, int n){
    double pay = 0;
    for(int i = n - 1; i >= 0; i--){
        if(salary >= a[i]){
            pay += (salary - a[i] + 1) * b[i];
            for(int j = i; i > 0; i--)
                pay += (a[i] - a[i - 1]) * b[i - 1];
            break;
        }
    }
    return pay;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> c[i];
    for(int i = 0; i < m; i++)
        cout << fixed << setprecision(2) << tax(c[i], n) << endl;
    return 0;
}
