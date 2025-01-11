#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--) {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;
        int res = INT_MAX ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
            res = min(res, nums[i]) ;
        }

        int ct = 0 ;
        for (int i : nums) if (i != res) ct++ ;

        cout << ct << endl ;


        
    }
    return 0 ;
}