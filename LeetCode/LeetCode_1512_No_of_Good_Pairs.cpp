#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int numIdenticalPairs(vector<int>& nums) {
    int ct = 0 ;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if(i < j && nums[i] == nums[j]) ct++ ;
        }
        
    }
    return ct ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0 ; i < n ; i++) cin >> nums[i] ;
    cout << numIdenticalPairs(nums) ;
    return 0 ;
}