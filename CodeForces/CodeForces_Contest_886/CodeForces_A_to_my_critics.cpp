#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;

    bool res = false ;

    while (t--) {
        int n = 3 ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        // for (int i = 0; i < n - 1; i++)
        // {
        //     for (int j = i+1; j < n; j++)
        //     {
        //         if (nums[i] + nums[j] >= 10) {res = true ;break ;}

        //     }
        //     if (res) break;
            
        // }

        if (nums[0] + nums[1] >= 10 || nums[0] + nums[2] >= 10 || nums[1] + nums[2] >= 10) cout << "YES\n" ;
        else cout << "NO\n" ;
        
        // cout << (res ? "YES\n" : "NO\n") ;
    }
    return 0 ;
}