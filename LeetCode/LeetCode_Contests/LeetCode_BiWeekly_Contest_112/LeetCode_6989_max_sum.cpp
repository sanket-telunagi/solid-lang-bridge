#include<bits/stdc++.h>
#include <iostream>
using namespace std ;



long long maxSum(vector<int>& nums, int m, int k) {
    int mod = 1e9 + 7 ;

    int left = 0 , right = 0 , mx = 0 , sum = 0, n = nums.size() , ct = 0;
    unordered_map<int, int> mp ;

    while (right < n) {
        
        if (right >= k) sum += nums[right] ;
        // prepare window 
        while (right < k) {
            sum += nums[right] ;
            if (mp[nums[right]] == 0) ct++ ;
            mp[nums[right]]++ ;
            right++ ;
        }

        // if window is formed 
        if (right - left + 1 == k) {
            if (ct == m) mx = max(mx, sum) ;
        }

        while (right - left + 1 > k) {
            mp[nums[left]]-- ;
            if (mp[nums[left]] == 0) ct-- ;
            left++ ;
        }

    }

    return mx ;
}

int main()
{
    int n, m , k ;
    cin >> n >> m >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << maxSum(nums, m , k) ;
    
    return 0 ;
}