#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;

        pair<int,int> MAX = {INT_MIN, 0}, MIN = {INT_MAX, 0} ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
            if(nums[i] > MAX.first) {

                MAX.first = max(MAX.first, nums[i]) ;
                MAX.second = i + 1;
            }
            if (nums[i] < MIN.first) {

                MIN.first = min(MIN.first, nums[i]) ;
                MIN.second = i + 1;
            }
        }
        
        int left_max_steps = max(MIN.second, MAX.second) ;
        int right_max_steps = n - (min(MIN.second, MAX.second)) + 1;
        int both_max_steps = n - (abs(MIN.second - MAX.second) - 1) ;



        
        // for (int it : nums) {
        //     if (it == MAX) break;
        //     ct++ ;
        // }
        // for (int it : nums) {
        //     if (it == MIN) break;
        //     ct++ ;
        // }
        
        // cout << left_max_steps << " " << right_max_steps << " " << both_max_steps << " " << min({left_max_steps, right_max_steps, both_max_steps}) << endl ;
        cout << min({left_max_steps, right_max_steps, both_max_steps}) << endl ;
    }
    
    return 0 ;
}