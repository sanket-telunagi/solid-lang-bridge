#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void solve(int idx, vector<int> & nums, vector<vector<int>> & ans) {
    if (idx == nums.size()){ 
        ans.push_back(nums);
        return ;
    }
    for (int i = idx; i < nums.size(); i++)
    {
       
        swap(nums[i], nums[idx]) ;
        solve(idx + 1, nums, ans) ;
        swap(nums[i], nums[idx]) ;
    }
    
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
    vector<vector<int>> ans ;
    solve(0, nums, ans) ;

    for (auto it : ans) {
        for (auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}