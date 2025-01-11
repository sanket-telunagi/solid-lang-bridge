#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        vector<int> nums(n), sums ;
        int sum = 0 ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
            sum += nums[i] ;
        }
        sort(nums.begin(), nums.end()) ;
        for (auto & it : nums) {
            sums.push_back(sum) ;
            sum -= it ;
        }
        
        for (auto & it : sums) {
            cout << it << " " ;
        }
        cout << endl ;

    }
    return 0 ;
}