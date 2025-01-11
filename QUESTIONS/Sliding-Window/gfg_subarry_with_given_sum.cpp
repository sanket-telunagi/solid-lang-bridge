/*

    Given an unsorted array A of size N that contains only non-negative integers, 
    find a continuous sub-array which adds to a given number S and 
    return the left and right index(1-based indexing) of that subarray.

    In case of multiple subarrays, return the subarray indexes 
    which comes first on moving from left to right.

    Note:- Both the indexes in the array should be according to 1-based indexing. 
    You have to return an arraylist consisting of two elements left and right. 
    In case no such subarray exists return an array consisting of element -1.

*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> subarraySum(vector<int>arr, int n, long long s)
{
    int i = 0 , j = 0 ;
    long long sum = 0 ;
    while (sum != s)
    {
        if (sum + arr[j] > s) {
            sum -= arr[i] ;
            i++ ;
        }
        // cout << i << " " << j << " " ;
        sum += arr[j]*1LL ;
        ++j ;
        if (sum == s) break;
        // cout << sum << endl ;
    }
    if (i == 0 && j == 0 && sum == 0) return {-1,-1} ;
    return {++i,j} ;
}

int main()
{
    int n ; 
    long long s;
    cin >> n >> s ;
    vector <int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    vector<int> ans = subarraySum(nums ,n , s) ;
    cout << ans[0] << " " << ans[1] << endl ;
    return 0 ;
}