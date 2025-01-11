/*
    Given the array nums consisting of 2n elements in 
    the form [x1,x2,...,xn,y1,y2,...,yn].

    Return the array in the form [x1,y1,x2,y2,...,xn,yn].
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans ;
    for (int i = 0; i < n; i++) {
        ans.push_back(nums[i]) ;
        ans.push_back(nums[i+n]) ;
    }
    return ans ; 
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++) cin >> nums[i] ;
    vector<int> ans = shuffle(nums, k) ;
    for(auto i : ans) cout << i << " " ;
    
    return 0 ;
}