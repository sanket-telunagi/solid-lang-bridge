#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Q : Given an integer array nums and an integer k, 
        return true if there are two distinct indices i and j in the 
        array such that nums[i] == nums[j] and abs(i - j) <= k.
*/

bool containsNearbyDuplicate (vector<int> & nums, int k) {
    int res = false ;
    int l = 0 , r = 0, n = nums.size() ;
    // while (r < n) {
    //     if (nums[l] == nums[r] && abs(l - r) <= k && l != r) {
    //         cout << l << " " << r << endl ;
    //         res = true ;
          
    //     } else if (abs(l - r) > k) {
    //         l++ ;

    //     }
    //     r++ ;
    // }

    unordered_map<int, vector<int>> mp ;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]].push_back(i) ;
    }

    for (auto & pr : mp) {
        for (int i = 0; i < pr.second.size()-1; i++)
        {
            if (abs(pr.second[i] - pr.second[(i+1)]) <= k && i != (i+1)) {
                res = true ;
                // cout << pr.second[i ]<< " " << pr.second[(i+1)] << endl ;
            }
        }
        
    }
    
    return res ;
}

int main()
{
    int n , k;
    cin >> n >> k;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << (containsNearbyDuplicate(nums, k) == 1 ? ( "true") :  "false"  ) << endl ;
    return 0 ;
}