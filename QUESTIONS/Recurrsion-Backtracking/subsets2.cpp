/*
    Given an integer array nums that may contain duplicates, return all possible subsets
    (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

void genSubsets(vector<int> & nums, vector<vector<int>> & ans, vector<int> & possible , set<vector<int>> hash,int index) {
    if (index == nums.size()) {
        hash.insert(possible) ; // inserting into hash
        if ( hash.find(possible) == hash.end()) {
            ans.push_back(possible) ;
        }
        return ;
    }

    // element is taken 
    genSubsets(nums, ans , possible, hash, index + 1) ;

    // element is taken 
    possible.push_back(nums[index]) ;
    genSubsets(nums, ans , possible, hash, index + 1) ;
    possible.pop_back() ;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans ;
    set<vector<int>> hash ;
    vector<int> empty ;
    genSubsets(nums, ans , empty, hash, 0) ;
    return ans ;
}

int main() {
    
    return 0 ;
}