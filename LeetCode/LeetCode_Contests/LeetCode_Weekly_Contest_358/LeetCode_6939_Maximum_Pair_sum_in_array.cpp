#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int max_digit(int num)  {
    int ans = 0 ;
    while (num > 0) {
        ans = max(ans, num % 10) ;
        num /= 10 ;
    }
    return ans ;
}

int maxSum(vector<int>& nums) {
    int res = -1 ;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (max_digit(nums[i]) == max_digit(nums[j])) {
                res = max(res, nums[i] + nums[j]) ;
            }
        }
        
    }

    return res ;
    
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> nums[i] ;
    }
    
    return 0 ;
}