#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given the dimension of a sequence of matrices in an array arr[], 
    where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to 
    multiply these matrices together such that the total number of element multiplications is minimum.

    Cost : 
        A = a x b 
        B = b x c
        cost (A X B) = a x b x c

*/

long long solve(int i, int j , vector<int> & nums) {

    // base condition : only one element : not possible to get dimention
    if (i == j) return 0 ;

    // start i = 1 end : j = n-1

    long long ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        long long left = solve(i, k, nums) ;
        long long right = solve(k + 1, j, nums) ;

        long long temp = (nums[i-1] * nums[k] * nums[j] * 1LL) + left + right ;
        ans = min(ans, temp) ;
    }
    
    return ans ;

}


long long MCM(vector<int> & nums) {
    long long cost = 0 ;
    cost = solve(1, nums.size() - 1, nums ) ;
    return cost ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums (n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << MCM(nums) << endl ;
    
    return 0 ;
}