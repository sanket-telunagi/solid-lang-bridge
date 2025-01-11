/*
    Given an integer array nums of unique elements, 
    return all possible subsets
    (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

void genSubsets(vector<int> &nums, vector<int> &out, vector<vector<int>> & ans , int index) {
    if (index == nums.size()) {
        ans.push_back(out) ;
        return ;
    }

    // element not chosen 
    genSubsets(nums, out , ans , index + 1) ;

    // element chosen
    out.push_back(nums[index]) ;
    genSubsets(nums, out , ans , index + 1) ;
    out.pop_back() ;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans ;
    vector <int> empty ;
    genSubsets(nums, empty, ans, 0) ;
    return ans ;
}

int main() {
    int n ;
    cin >> n ;
    vector <int> v(n) ;

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i] ;
    }

    vector<vector<int>> ans ;
    ans = subsets(v) ;
    for (auto it : ans) {
        for (auto i : it ) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    
    return 0 ;
}