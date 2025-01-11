#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        bool isSatisified = true ;

        for (int i = 0; i < n - 1; i++)
        {
            if (!(abs(nums[i] - nums[i+1]) <= 1)) {
                isSatisified = false ;
                break ;
            }
        }
        cout << (isSatisified ? "YES\n" : "NO\n") ;
        
    }
    
    return 0 ;
}