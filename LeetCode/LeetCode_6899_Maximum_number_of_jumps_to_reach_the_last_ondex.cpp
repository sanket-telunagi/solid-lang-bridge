#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int solve(vector<int> & nums, int i ) {
    if (i < 0 || j < 0) return 0 ;
    int n = nums.size() ;

    
    
}

int maximumJumps(vector<int>& nums, int target) {
        // int ct = 0 ;
        // int n = nums.size() ;
        // int l = 0 , r = 1 ;
        // while ( r < n && r < 1000) {
            
        //     for (int j = r; j < n; j++)
        //     {
                
        //         if (abs(nums[j] - nums[r]) <= target) {
        //             ct++ ;
        //             l = r ;
        //             r = j ;
        //             break ;
        //         }
        //     }
            

        //     r++ ;
        // }
        // if (ct == 0 || l != n-1) return -1 ;
        // return ct ;

    }

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << maximumJumps(nums, k) ;
    return 0 ;
}