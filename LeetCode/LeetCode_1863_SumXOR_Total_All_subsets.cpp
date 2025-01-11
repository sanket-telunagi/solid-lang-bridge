#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// generate subsets and instead of storing them stor the xor of each subset

// void genSubsets(vector<int> & nums,vector<int> & subset, vector<int> & xorTotals, int index) {
//     if(index == nums.size()){
//         int ans = 0 ;
//         for (int i = 0 ; i < subset.size() ; i++) {
//             ans ^= subset[i] ;
//         }
//         xorTotals.push_back(ans) ;
//         return ;
//     }

//     // number is not taken
//     genSubsets(nums,subset,xorTotals,index + 1) ;

//     // number is taken 
//     subset.push_back(nums[index]) ;
//     genSubsets(nums,subset,xorTotals,index + 1) ;
//     subset.pop_back() ;

// }

void genSubsetsBitMask(vector<int> & nums, vector<int> & XORTotals ) {

    int n = nums.size() ;
    int subset_ct = (1 << n) ;
    for (int mask = 0; mask < subset_ct; mask++)
    {
        int temp = 0 ;
        for (int i = 0; i < n; i++)
        {
            if((mask & (1<<i)) != 0) {
                temp ^= nums[i] ;
            }
        }
        XORTotals.push_back(temp) ;
    }
}

int subsetXORSum(vector<int>& nums) {
    // ---- Recurssion Method
        // vector<int> empty, xors ;
        // genSubsets(nums, empty, xors, 0) ;

    // ---- Iterative Method 
    vector<int> xors ;
    genSubsetsBitMask(nums,xors) ;
    return accumulate(xors.begin(),xors.end(),0) ;
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
    cout << subsetXORSum(nums) ;
    return 0 ;
}