/*
    Given an array nums of distinct integers, return all the possible permutations. 
    You can return the answer in any order.

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

void genPermutaions(vector<int> & nums , vector<vector<int>> & ans, int index) {
    // base condition 
    if (index == nums.size()) {
        
        ans.push_back(nums) ;
        return ;
    }
    
    // processing 
    for(int i = index; i < nums.size() ; i++) {
        swap(nums[index],nums[i]) ;
        genPermutaions(nums,ans,index+1) ;
        swap(nums[index],nums[i]) ;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans ;
    genPermutaions(nums, ans , 0) ;
    return ans ;
}

int main() {
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i] ;
    }
    vector<vector<int>> ans ;
    ans = permute(nums) ;
    for (auto it : ans) {
        for (int i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}