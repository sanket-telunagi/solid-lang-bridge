#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int get_mejority(vector<int> & nums) {
    int ct = 0 , major = 0 , major_ct = 0;
    sort(nums.begin(), nums.end()) ;
    major = nums[0] ;
    for (int i = 0; i < nums.size(); i++)
    {
        ct++ ;

        if (ct > major_ct) {
            major = nums[i] ;
            major_ct = ct ;
        }

        if (nums[i] != major) {
            major_ct = ct ;
        }

    }
    return major ;
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
    cout << get_mejority(nums) ;
    return 0 ;
}