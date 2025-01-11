/*

    Given an integer array nums that may contain duplicates, return all possible subsets
    (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

void genSubsets(vector<int> &nums, vector<int> &out, set<vector<int>> & ans , int index) {
    if (index == nums.size()) {
        ans.insert(out) ;
        return ;
    }

    // element not chosen 
    genSubsets(nums, out , ans , index + 1) ;

    // element chosen
    out.push_back(nums[index]) ;
    genSubsets(nums, out , ans , index + 1) ;
    out.pop_back() ;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> ans ;
    vector <int> empty ;
    genSubsets(nums, empty, ans, 0) ;
    vector<vector<int>> vans ;
    for (auto it : ans){
        vans.push_back(it) ;
    }
    return vans ;
}

int main() {
    int n ;
    cin >> n ;
    vector <int> v(n) ;

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i] ;
    }

    vector<vector<int>> ans ;
    ans = subsetsWithDup(v) ;
    for (auto it : ans) {
        for (auto i : it ) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    
    return 0 ;
}