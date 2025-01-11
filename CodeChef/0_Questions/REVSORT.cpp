#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;

    while (t--) 
    {
        int n , k;
        cin >> n >> k;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        int l = 0 ,
            r = 0 ,
            isAble = true ;
        /*
            A way of choosing pairs
        */
        for ( l = 0, r = l + 1 ; l < n - 1 && r < n; r++, l++)
        {
            // cout << nums[l] << " " << nums[r] << endl ;
            if (nums[l] > nums[r]) {
                if (nums[l] + nums[r] <= k) {
                    swap(nums[l], nums[r]) ;
                } else {
                    isAble = false ;
                }
            }
        }

        cout << (isAble ? "YES\n" : "NO\n") ;
    }
    
    
    return 0 ;
}