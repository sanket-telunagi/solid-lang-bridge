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
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }
        // sort 
        sort (nums.begin(), nums.end()) ;

        // check if the diff is atmost 1 
        bool res = true ;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i+1] - nums[i] > 1) res = false ;
        }
        cout << (res ? "YES\n" : "NO\n") ;
    }
    return 0 ;
}