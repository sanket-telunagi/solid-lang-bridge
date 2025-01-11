#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/* 
    The maximum element with be included definately 
    

*/

int main()
{
    int t;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        // int arr[n] ;
      
        vector<long long > nums(n) ;
        for (int i = 0; i < n; i++)
        {
            // cin >> arr[i] ;
         

            cin >> nums [i] ;

        }
        long long res = 0 ;
        for (int i = 0; i < n - 1; i++)
        {
            res = max(res, nums[i] * nums[i+1]* 1LL) ;
        }
    cout << res << endl ;
        
        
    }
    return 0 ;
}