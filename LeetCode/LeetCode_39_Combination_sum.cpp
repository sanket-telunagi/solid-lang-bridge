#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given an array of distinct integers candidates and a target integer target, 
    return a list of all unique combinations of candidates where the chosen numbers 
    sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. 
    Two combinations are unique if the frequency
    of at least one of the chosen numbers is different.

    The test cases are generated such that the number of unique 
    combinations that sum up to target is less than 150 combinations 
    for the given input.
*/

void genCombinations(vector<int> & arr, vector<int> & empty, vector<vector<int>> & ans, int & k, int index = 0) {
    if (index >= arr.size()) {
        if (accumulate(empty.begin(),empty.end(), 0) == k) {
            ans.push_back(empty) ;
        }
        return ;
    }
    // current index not taken
    genCombinations(arr, empty, ans, k ,index + 1) ;

    // current index taken
    for (int child : arr) {
        empty.push_back(arr[child]) ;
        genCombinations(arr, empty, ans, k , index + 1) ;
        empty.pop_back() ;
    }
    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> empty ;
    vector<vector<int>> ans ;
    genCombinations(candidates, empty, ans, target) ;
    return ans ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> candidates(n) ;
    for(int i =0 ; i < n ; i++) cin >> candidates[i] ;

    vector<vector<int>> ans = combinationSum(candidates, k) ;

    for (auto it : ans)
    {
        for (int i : it ){
            cout << i << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}