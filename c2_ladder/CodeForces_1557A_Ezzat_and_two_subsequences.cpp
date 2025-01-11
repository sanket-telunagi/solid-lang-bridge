#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;

        // choose datatype wisely 
        
        long double sum = 0 ;
        int max_ele = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
            sum += nums[i] ;
            max_ele = max(max_ele, nums[i]) ;
        }

        long double res = max_ele + (sum - max_ele) / (n - 1) ;

        // sort(nums.begin(), nums.end()) ;

        // cout << setprecision(9) << (*max_element(nums.begin(), nums.end())+ float(accumulate(nums.begin(), nums.end(), 0) - *(max_element(nums.begin(), nums.end())))/ (n - 1)) << endl ;
        cout << setprecision(11) << res << endl ;
    }
    return 0 ;
}