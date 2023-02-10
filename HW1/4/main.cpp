#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq;
    queue<int> q;
    int n, com;
    cin >> n;
    while(n--){
        cin >> com;
        if(com == 1){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(com == 3){
            if(!pq.empty()){
                cout << pq.top() << endl;
                pq.pop();
            }
            else if(!q.empty()){
                cout << q.front() << endl;
                q.pop();
            }
            else
                cout << "Oh Oh" << endl;
        }
        else{
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}
