#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Q : Return true if the subset can be partitioned into two subsets with equal sum 
    A : A the given array is parttitioned into two subsets with same sum 
        If one subset is of sum 's' the the remaining subset will be of sum "total_sum - s == s" 
        hence, proble reduces to findthe subset of sum 's' in the array 
*/


bool equal_partition_recursive(int idx, int sum, vector<int> & nums) {
    if (sum == 0) return true ; // the given sum exists 
    if (idx < 0) return false ; // sum does not exists in the array

    // Current index is not taken 
    bool res = equal_partition_recursive(idx - 1, sum, nums) ;

    // current sum taken 
    if (sum >= nums[idx])
    res |= equal_partition_recursive(idx -1 , sum - nums[idx], nums) ;

    // return true if any of the subset sums to given sum 
    return res ;
}

int memoise[510][510] ;

bool equal_partition_memoisation(int idx, int sum, vector<int> & nums) {
    if (sum == 0) return true ; // the given sum exists 
    if (idx < 0) return false ; // sum does not exists in the array

    if (memoise[idx][sum] != -1 ) return memoise[idx][sum] ;
    // Current index is not taken 
    bool res = equal_partition_memoisation(idx - 1, sum, nums) ;

    // current sum taken 
    if (sum >= nums[idx])
    res |= equal_partition_memoisation(idx - 1 , sum - nums[idx], nums) ;

    // return true if any of the subset sums to given sum 

    return memoise[idx][sum] = res ;
}

bool equal_partition_tabulation(int sum , vector<int> & nums) {
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
    int n;
    std :: cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        std :: cin >> nums[i] ;
    }
    memset(memoise, -1, sizeof(memoise)) ;
    
    int sum = accumulate(nums.begin(), nums.end(), 0) ; // sum of whole array 
    sum = 2 ; // partioned sum 

    std :: cout << equal_partition_recursive(n-1, sum, nums) ;
    // std :: cout << equal_partition_memoisation(n-1, sum, nums) << endl ;
    // for (int i = 0; i < 510; i++)
    // {
    //     for (int j = 0; j < 510; j++)
    //     {
    //         std :: cout << memoise[i][j] << " " ;
    //     }
    //     std :: cout << endl ;
        
    // }
    // 
    // std :: cout << equal_partition_tabulation(sum, nums) ;


    return 0 ;
}