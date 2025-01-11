#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

unordered_map<string, int> mp ;

int solve(int l, int r, vector<int> nums) {
    if (l == r) return nums[r] ; // at the center of array or only one element 
    string key = to_string(l) + " " + to_string(r) ;

    if (mp.find(key) != mp.end()) return mp[key] ;
    
    int leftSC = nums[l] - solve(l + 1, r, nums) ;
    int rightSC = nums[r] - solve(l, r - 1, nums) ;

    return mp[key] = max(leftSC, rightSC) ;
}

bool PredictTheWinner(vector<int>& nums) {
    return solve(0, nums.size() - 1, nums) >= 0 ;
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

    cout << PredictTheWinner(nums) << endl ;
    
    return 0 ;
}