#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int subsetsum_recursion(int idx, int sum, vector<int> & nums) {
    if (sum == 0) return 1 ; // the given sum exists 
    if (idx < 0) return 0 ; // sum does not exists in the array

    // Current index is not taken 
    int res = subsetsum_recursion(idx - 1, sum, nums) ;

    // current sum taken 
    res += subsetsum_recursion(idx -1 , sum - nums[idx], nums) ;

    // return true if any of the subset sums to given sum 

    return res ;
}

int memoise[510][510] ;

bool subsetsum_memoisation(int idx, int sum, vector<int> & nums) {
    if (sum == 0) return 1 ; // the given sum exists 
    if (idx < 0) return 0 ; // sum does not exists in the array

    if (memoise[idx][sum] != -1) return memoise[idx][sum] ;

    // Current index is not taken 
    int res = subsetsum_recursion(idx - 1, sum, nums) ;

    // current sum taken 
    res += subsetsum_recursion(idx -1 , sum - nums[idx], nums) ;

    // return true if any of the subset sums to given sum 

    return memoise[idx][sum] = res ;
}

int main()
{
    int n, k ;
    std :: cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        std :: cin >> nums[i] ;
    }
    memset(memoise, -1, sizeof(memoise)) ;

    // cout << subsetsum_recursion(n - 1, k, nums) << endl ;
        cout << subsetsum_memoisation (n , k, nums) << endl ;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cout << memoise[i][j] << " " ;
            }
            cout << endl ;
            
        }
        

    
    return 0 ;
}