#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n , wt ;
        cin >> n >> wt ;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        /*
            sort the array as the 
            Problem reduces to finding minimum window size with sum wt
        */
        sort (nums.begin(), nums.end()) ;
        int size = INT_MAX ;
        int l = 0 , r = 0, sum = 0 ;
        while (r < n) {
            sum += nums[r] ;
            while (sum >= wt) {
                size = min(size, r - l + 1) ;
                sum -= nums[l] ;
                l++ ;
            }
            r++ ;
        }

        cout << n - size << endl;
        
    }
    return 0 ;
}