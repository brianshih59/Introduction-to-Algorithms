#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    short num;
    vector<short> scores(n, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++){
            cin >> num;
            scores[i] += num;
        }
    sort(scores.begin(), scores.end());
    for(int i = n - 1; i >= 0; i--)
        cout << scores[i] << "\n";
    return 0;
}
