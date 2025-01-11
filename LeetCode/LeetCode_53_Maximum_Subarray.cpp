#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int maxSubArray(vector<int> & nums)  {
    int n = nums.size() ;
    int ans = INT_MIN , sum = 0 ;
    int s = 0 , e = 0 ;
    while (s <= e)
    {
       
        cout << nums[s] << " " << nums[e] << endl ;
        if (e != (n-1)) {
            sum += nums[e] ;
            ans = max(ans, sum) ;
            e += 1;
            continue;
        }
        s += 1 ;
        ans = max(ans, sum) ;
        sum -= nums[s] ;
    }
    return ans ;
}

int main()
{
    int n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << maxSubArray(nums) << endl ;
    return 0 ;
}