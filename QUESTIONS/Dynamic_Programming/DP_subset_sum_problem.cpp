#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Q : Given an array "nums" and a sum "sum" 
        Return "true" if any subset of array sum to given number 
        else return false 
*/

bool subsetsum_recursion(int idx, int sum, vector<int> & nums) {
    if (sum == 0) return true ; // the given sum exists 
    if (idx < 0) return false ; // sum does not exists in the array

    // Current index is not taken 
    bool res = subsetsum_recursion(idx - 1, sum, nums) ;

    // current sum taken 
    res |= subsetsum_recursion(idx -1 , sum - nums[idx], nums) ;

    // return true if any of the subset sums to given sum 

    return res ;
}

int memoise[510][510] ;

bool subsetsum_memoisation(int idx, int sum, vector<int> & nums) {
    if (sum == 0) return true ; // the given sum exists 
    if (idx < 0) return false ; // sum does not exists in the array

    if (memoise[idx][sum] != -1 ) return memoise[idx][sum] ;
    // Current index is not taken 
    bool res = subsetsum_memoisation(idx - 1, sum, nums) ;

    // current sum taken 
    res |= subsetsum_memoisation(idx -1 , sum - nums[idx], nums) ;

    // return true if any of the subset sums to given sum 

    return memoise[idx][sum] = res ;
}

bool subsetsum_table(int sum , vector<int> & nums) {
    int n = nums.size() ;
    bool table[n + 1][sum + 1] ;
    for (int i = 0; i <= sum; i++)
    {
        table[0][i] = false ; // no sum possible with empty array 
    }
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = true ; // sum = 0 possible with any size of array 
    }
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (nums[i-1] <= j) {
                
                table[i][j] = table[i-1][j] | table[i-1][j - nums[i - 1]] ;
            } else {
                table[i][j] = table[i-1][j] ;
            }

            // std :: cout << table[i][j] << " " ;
        }
        // std :: cout << endl ;
    }
    
    return table[n][sum] ;
}

int main()
{
    int n, k;
    std :: cin >> n >> k;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        std :: cin >> nums[i] ;
    }
    memset(memoise, -1, sizeof(memoise)) ;
   

    // std :: cout << subsetsum_recursion(n-1, k, nums) ;
    // std :: cout << subsetsum_memoisation(n-1, k, nums) ;
    std :: cout << subsetsum_table(k, nums) ;


    return 0 ;
}