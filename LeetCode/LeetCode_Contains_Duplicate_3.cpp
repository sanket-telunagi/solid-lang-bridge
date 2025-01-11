#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
Q : 
    You are given an integer array nums and two integers indexDiff and valueDiff.

    Find a pair of indices (i, j) such that:

    i != j,
    abs(i - j) <= indexDiff.
    abs(nums[i] - nums[j]) <= valueDiff, and
    Return true if such pair exists or false otherwise.
*/

bool containsNearbyAlmostDuplicate(vector<int> & nums, int indexDiff, int valueDiff) {
    bool res = false ;
    int n = nums.size() ;
    // unordered_map<int, vector<int>> mp ;
    // for (int i = 0; i < n; i++)
    // {
    //     mp[nums[i]].push_back(i) ;
    // }

    // for (auto & pr : mp) {
    //     for (int i = 0; i < pr.second.size()-1; i++)
    //     {
    //         int j = i + 1; 
    //         if (abs(pr.second[i] - pr.second[j]) <= indexDiff && i != j && abs(nums[pr.second[i]] - nums[pr.second[i+1]]) <= valueDiff) {
    //             res = true ;
    //             cout << pr.second[i ]<< " " << pr.second[j] << endl ;
    //         }
    //     }
        
    // }

    for (int i = 0 ; i <= n - indexDiff + 1; i++) {
        int j = i + indexDiff ;
        // cout << nums[i] << " " << nums[j] << endl ;
        if (abs(i - j) <= indexDiff) {
            for (int k = i + 1; k <= j; k++) {
                if (k < n && i < n)
                if (abs(nums[k] - nums[i]) <= valueDiff && abs(k - i) <= indexDiff) res = true ;
            }
        }
    }
    
    return res ;
}

int main()
{
    int n , indexDiff, valueDiff ;
    cin >> n >> indexDiff >> valueDiff ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << (containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) == 1 ? "true" : "false") << endl ;
    
    return 0 ;
}