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
        /*
            The onservation is that 
            when the k < n 
                maximum value that can be acheived by given conditions is the kth minimum value
                or the value at kth position when sorted the array in ascending order 
            when k >= n
                the maximum value in the array can be acheived to every element in the array 
        */

       if (k >= n) cout << *max_element(nums.begin(), nums.end()) << endl ;
       else {
            sort(nums.begin(), nums.end()) ;
            cout << nums[k] << endl ;
       }
        
    }
    return 0 ;
}