#include <iostream>
#include <vector>
#define INF 2e9
using namespace std;

tuple<int,int,int> find_max_crossing_subarray(const vector<int>& A, int low, int mid, int high) {
    int max_left_sum = -INF;
    int sum = 0, left_low = mid, right_high = mid+1;
    for(int i = mid; i >= low; --i) {
        sum += A[i];
        if(sum >= max_left_sum) {
            max_left_sum = sum;
            left_low = i;
        }
    }
    int max_right_sum = -INF;
    sum = 0;
    for(int i = mid+1; i <= high; ++i) {
        sum += A[i];
        if(sum >= max_right_sum) {
            max_right_sum = sum;
            right_high = i;
        }
    }
    return {left_low, right_high, max_left_sum+max_right_sum};
}

tuple<int,int,int> find_maximum_subarray(const vector<int>& A, int low, int high) {
    if(low == high) return {low, high, A[low]};
    int mid = low + (high-low)/2;
    auto [left_low, left_high, left_sum] = find_maximum_subarray(A, low, mid);
    auto [right_low, right_high, right_sum] = find_maximum_subarray(A, mid+1, high);
    auto [cross_low, cross_high, cross_sum] = find_max_crossing_subarray(A, low, mid, high);
    if(left_sum >= right_sum && left_sum >= cross_sum) return {left_low, left_high, left_sum};
    else if(right_sum >= left_sum && right_sum >= cross_sum) return {right_low, right_high, right_sum};
    else return {cross_low, cross_high, cross_sum};
}

int main() {
    int n; cin >> n;
    vector<int> A(n);
    for(auto& e: A) cin >> e;
    auto [low, high, sum] = find_maximum_subarray(A, 0, n-1); 
    cout << low << " " << high << " " << sum << endl;
}