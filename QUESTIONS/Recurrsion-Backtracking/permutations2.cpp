/*
    Given a collection of numbers, nums, that might contain duplicates, 
    return all possible unique permutations in any order.
*/

#include<bits/stdc++.h>
#include<iostream>

void genPermutaions(vector<int> & nums , set<vector<int>> & ans, int index) {
    // base condition 
    if (index == nums.size()) {
        
        ans.insert(nums) ;
        return ;
    }
    
    // processing 
    for(int i = index; i < nums.size() ; i++) {
        swap(nums[index],nums[i]) ;
        genPermutaions(nums,ans,index+1) ;
        swap(nums[index],nums[i]) ;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    set<vector<int>> ans ;  // set always store unique elements 
    genPermutaions(nums, ans , 0) ;
    vector<vector<int>> vans ;
    for (auto it : ans){
        vans.push_back(it) ;
    }
    return vans ;
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