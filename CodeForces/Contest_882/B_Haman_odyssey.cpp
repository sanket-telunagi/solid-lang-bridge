#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int fun(vector<int> & nums, int i , int j ) {

}

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        vector<int> nums(n) ;


        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }
        int th = nums[0] ;
        int ct = 0 ;
        int r = 0 , l = 0 ;
        // while (r < n) {
        //     th &= nums[r] ;
        //     if (th == 0) {
        //         ct++ ;
        //         while (th == 0 && r < n) {
        //             th &= nums[r] ;
        //             r++ ;
        //         }
        //         th = nums[r-1] ;
        //         continue;
        //     }
        //     r++ ;
        // }
        for (int i = 0; i < n; i++)
        {
            th &= nums[i] ;
            if (th == 0) {
                ct++ ;
                while (th == 0) {
                    th &= nums[r] ;
                    r++ ;
                }
                if (r < n)
                th = nums[r-1] ;
            }
        }
        
        cout << (ct == 0 ? 1 : ct) << endl ;
        
        

        
    }
    
    return 0 ;
}