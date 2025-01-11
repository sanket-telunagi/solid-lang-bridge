#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int countPairs(vector<int>& nums, int target) {
    int ct = 0 , n = nums.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (nums[i] + nums[j] < target) ct++ ;
        }
        
    }
    return ct ;
}

int main()
{
    int n, target ;
    cin >> n >> target ;

    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << countPairs(nums, target) << endl ;
    
    return 0 ;
}