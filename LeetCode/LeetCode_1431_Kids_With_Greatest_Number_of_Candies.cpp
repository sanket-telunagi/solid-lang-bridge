/*
    There are n kids with candies. You are given an integer array candies, 
    where each candies[i] represents the number of candies the ith kid has, 
    and an integer extraCandies, denoting the number of extra candies that you have.

    Return a boolean array result of length n, where result[i] is true if, 
    after giving the ith kid all the extraCandies, 
    they will have the greatest number of candies among all the kids, or false otherwise.

    Note that multiple kids can have the greatest number of candies.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans ;
    int max_Can = *max_element(candies.begin(),candies.end()) ;
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= max_Can) ans.push_back(true) ;
        else ans.push_back(false) ;
    }
    return ans ;
}

int main()
{
    int n, k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    vector<bool> ans;
    for (int i = 0; i < n ; i++) cin >> nums[i] ;
    ans = kidsWithCandies(nums, k) ;
    for (auto i : ans) cout << i << " " ;
    
    return 0 ;
}