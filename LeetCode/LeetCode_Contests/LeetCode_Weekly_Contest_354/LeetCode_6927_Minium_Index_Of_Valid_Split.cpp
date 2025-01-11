#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int minimumIndex(vector<int> & nums) {
    int res = -1 ,
        n = nums.size();
    
    int domE = 0 ,
        ele = INT_MIN;
    unordered_map<int,int> mp ;
    for(auto it : nums) {
        if (mp[it] > ele) {
            domE = it ;
            ele = mp[it] ;
        }
        mp[it]++ ;
    }
    // cout << domE << endl ;
    int ct = 0 ;
    // bool isPossible = false ;
    // for (int i = 0; i < n; i++)
    // {
    //     if (nums[i] == domE) ct++ ;
    //     if (ct * 2 > (i + 1)) {
    //         res = i ;
    //         cout << ct << " " << i << endl ;
    //         ct = 0 ;
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             // cout  << n - i - 1 << endl ;
    //             if (nums[j] == domE) ct++ ;
    //             if (ct * 2 > (n - i - 1)) {
    //                 isPossible = true ;
    //             }
    //         }
            
    //         if (isPossible) {
    //             break ;
    //         } else {
    //             return -1 ;
    //         }
    //     }
    // }

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == domE) ct++ ;
        int left_ct = ct ;
        int right_ct = mp[domE] - ct ;
        if (left_ct * 2 > i + 1 && right_ct * 2 > (n - (i+1))) {
            return i ;
        }
    }
    return -1 ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << minimumIndex(nums) << endl ;
    
    return 0 ;
}