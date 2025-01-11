#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--)
    {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;
        unordered_map<int,int> mp ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
            mp[nums[i]]++ ;
        }
        /*
            If numbers are repeated the maximum height after each increment is (freq - 1)
            and still if the maximum element exists in the array then we can take it 
        */
        // cout << *(max_element(nums.begin(), nums.end())) << endl ;
        int res = 0 ;
        for (auto & it : mp) {
            res = max(res, (it.first + it.second - 1)) ;
        }
        cout << res << endl ;
    }
    return 0 ;
}