#include<bits/stdc++.h>
#include <iostream>
using namespace std ;
 
int main()
{
    long long t ;
    cin >>t ;
    while (t--)
    {
        long long n ;
        cin >> n ;
        vector<long long> nums(n,0) ;
        for (long long i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        for (int num : nums) cout << num << " ";
 
        // cout << (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()) )<< endl ;
        
    }
    
    return 0 ;
}