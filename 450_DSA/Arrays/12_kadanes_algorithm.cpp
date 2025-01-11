#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Kadanes Algorithm : 

        it is the algorithm to find maximum sum subarray from the given list of numbers 

        it works by adding number numbers untill the current sum >= 0 
        else if current sum < 0 then set the current number to the current number 
        now set the maximum of max_sum and current sum 
        return the maximum sum 

*/

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    long long int max_sum = INT_MIN , curr_sum = 0 ;
    for (int i = 0; i < n; i++)
    {
        if (curr_sum >= 0) curr_sum += nums[i] ;
        else curr_sum = nums[i] ;
        max_sum = max(max_sum, curr_sum) ;
    }

    cout << max_sum << endl ;
    
    
    return 0 ;
}