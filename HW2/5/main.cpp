#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll A, B;
ll count_building(vector<int>& building, int start, int End){
    if(start > building.back())
        return 0;
    while(End > building.back())
        End--;
    int a, b;
    int left = 0, right = building.size() - 1, target = start;
    while(left < right){
        int mid = (left + right) / 2;  // mid偏左
        if(building[mid] < target)
            left = mid + 1;
        else  // 讓nums[mid] == target時right往left靠
            right = mid;
    }
    if(building[left] < target)
        left++;
    a = left;
    left = 0, right = building.size() - 1, target = End;
    while(left < right){
        int mid = (left + right + 1) / 2;  // mid偏右
        if(building[mid] > target)
            right = mid - 1;
        else  // 讓nums[mid] == target時left往right靠
            left = mid;
    }
    if(building[right] > target)
        right--;
    b = right;
    if(a > b)
        return 0;
    return b - a + 1;
}
ll partition(vector<int>& building, int start, int End){
    if(start == End){
        ll num = count_building(building, start, start);
        if(!num)
            return A;
        else
            return B * num;
    }
    int mid = start + (End - start) / 2;
    ll sum = 0;
    ll first_half = count_building(building, start, mid);
    if(!first_half)
        sum += A;
    else
        sum += partition(building, start, mid);
    ll second_half = count_building(building, mid + 1, End);
    if(!second_half)
        sum += A;
    else
        sum += partition(building, mid + 1, End);
    sum = min(sum, B * (End - start + 1) * (first_half + second_half));
    return sum;
}
int main(){
    int n, k;
    cin >> n >> k >> A >> B;
    vector<int> building(k);
    for(int i = 0; i < k; i++){
        int j;
        cin >> j;
        --j;
        building[i] = j;
    }
    sort(building.begin(), building.end());
    cout << partition(building, 0, n - 1);
    return 0;
}
