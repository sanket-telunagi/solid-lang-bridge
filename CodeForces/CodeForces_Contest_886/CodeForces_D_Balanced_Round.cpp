#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n , k ;
        cin >> n >> k ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        sort(nums.begin(), nums.end()) ;

        if (n == 1) cout << 0 << endl ;
        else {

            int ct = 0 ;
            for (int i = 0; i < n - 1; i++)
            {
                if (nums[i+1] - nums[i] >  k) ct++ ;
            }
            
            cout << ct << endl ;
        }
        
    }
    return 0 ;
}