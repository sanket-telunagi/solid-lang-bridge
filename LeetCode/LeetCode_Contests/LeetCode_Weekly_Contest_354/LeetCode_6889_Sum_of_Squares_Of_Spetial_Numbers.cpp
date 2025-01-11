#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int sumOfSquares(vector<int>& nums) {
    int n = nums.size(),
        sum = 0 ;

    for (int i = 0; i < n; i++)
    {
        if (n % (i + 1) == 0) {
            sum += nums[i] * nums[i] ;
        }
    }
    return sum ;
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

    cout << sumOfSquares(nums) << endl ;
    
    return 0 ;
}