#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isGood(vector<int>& nums) {
    int n = nums.size() ;

    if (n == 1) return false ;
    // sorting
    sort(nums.begin(), nums.end()) ;



    if (nums[n-1] == nums[n-2]) {
        for (int i = 0; i < n -1; i++)
        {
            if (nums[i] != i+1) {
                return false ;
            }
        }
        return true ;
    }
    return false ;
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
    cout << isGood(nums) << endl ;
    return 0 ;
}