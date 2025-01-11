/*
    Given an integer array nums, return all the different possible 
    non-decreasing subsequences of the given array
    with at least two elements. You may return the answer in any order.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

set<vector<int>> subarray ;

void generate(int index, vector<int> & nums, vector<int> & arr) {
    if (index >= nums.size()) {
        if (arr.size() >= 2) {
            subarray.insert(arr) ;
        }
        return ;
    }

    // element not taken
    
    generate(index+1, nums, arr) ;

    arr.push_back(nums[index]) ;
    generate(index+1, nums, arr) ;
    arr.pop_back() ;
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ans ;
    vector<int> empty ;
    generate(0,nums,empty) ;
    for(auto & it : subarray) {
        bool flag = true ;
        for(int i = 0 ; i < it.size() - 1 ; i++) {
            if (it[i + 1] < it[i]) {
                flag = 0 ;
                break;
            }
        } ;
        if (flag) {
            ans.push_back(it) ;
        }
    }
    return ans ;
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
    for (auto & it : findSubsequences(nums)) {
        for(auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    
    return 0 ;
}