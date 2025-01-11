#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

int max_sum_subarray(vector<int> & nums, int k) {
    int l = 0, sum = 0 , res = INT_MIN ;

    for (int r = 0; r < nums.size(); r++)
    {
        while(r - l + 1 < k) {
            sum += nums[r] ;
            r++ ;
        }
        sum += nums[r] ;
        res = max(res, sum) ;
        sum -= nums[l] ;
        l++ ;
    }
    return res ;
}

int main() {
    int n , k;
    cin >> n >> k;

    vector<int> nums(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i] ;
    }

    cout << max_sum_subarray(nums, k) ;
    return 0 ;
}