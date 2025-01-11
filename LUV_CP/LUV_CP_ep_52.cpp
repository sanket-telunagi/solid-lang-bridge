/*
    generate sy=ubsets using bit masking 
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<vector<int>> genSubsets(vector<int> & nums) {
    vector<vector<int>> subsets ;
    int n = nums.size() ;
    int subset_ct = 1 << n ;
    for (int mask = 0; mask < subset_ct; mask++)
    {
        vector<int> subset ;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1<<i)) != 0 ) {
                subset.push_back(nums[i]) ;
            }
        }
        subsets.push_back(subset) ;
    }
    return subsets ;
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
    vector<vector<int>> ans = genSubsets(nums) ;
    for(auto it : ans) {
        for(int i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    return 0 ;
}