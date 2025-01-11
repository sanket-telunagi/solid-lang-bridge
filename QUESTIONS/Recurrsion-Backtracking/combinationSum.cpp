/*
    Given an array of distinct integers candidates and a target integer target, 
    return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. 
    Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

void findCombination(vector<int> & candidates, vector<int> & possible ,int target, vector<vector<int>> & ans, int index) {

    if(index != candidates.size()) possible.push_back(candidates[index]) ;

    if (index == candidates.size()) {
        if (accumulate(possible.begin(), possible.end(), 0) == target) {
            ans.push_back(possible) ;
        }
        return ;
    }
    // element had not taken to ckeck
    findCombination(candidates, possible, target, ans, index + 1) ;

    // element had taken to check
    possible.push_back(candidates[index]) ;
    findCombination(candidates, possible, target, ans, index + 1) ;
    possible.pop_back() ; // undo changes backtrack

    for (int i : possible) {
            cout << i << " " ;
        }
        cout << endl ;
    

    possible.pop_back() ;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans ;
    vector<int> possible ;
    findCombination(candidates, possible, target , ans , 0) ;

    for(int i : candidates) {
        if (i == target) {
            possible.push_back(i) ;
            ans.push_back(possible) ;
            possible.pop_back() ;
        }
    }

    return ans ;
}

int main() {
    int n ,k ;
    cin >> n >> k;
    vector<int> candidates(n) ;
    for (int i = 0 ; i < n ; i++) {
        cin >> candidates[i] ;
    }

    vector<vector<int>> ans ;
    ans = combinationSum(candidates, k) ;
    // for(auto it : ans) {
    //     for (int i : it) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }
    return 0 ;
}

