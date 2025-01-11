#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;
        int k = 3 ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }
        // sort(nums.begin(), nums.end()) ;
        int l = 0 , r = 0 , sum = 0 ;
        int ct = 0 ;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i] ;
        }

        if (sum % 3 != 0) {
            nums[2] += (sum % 3) ;
            ct++ ;
            sum += (sum % 3) ;
        }

        for (r = 3; r < n; r++)
        {
            
            sum -= nums[l] ;
            l++ ;
            sum += nums[r] ;
            if (sum % 3 != 0) {
                nums[r] += (sum % 3) ;
                ct++ ;
                sum += (sum % 3) ;
            } 

        }
        
        
        
        

        cout << ct << endl ;
        
        

        
    }
    return 0 ;
}