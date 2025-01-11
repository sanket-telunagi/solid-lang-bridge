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
        // sort it and get the rest of the elements excluding first and last k
        sort (nums.begin(), nums.end()) ;
        // dtype "double" is important
        double sum = 0 ;
        for (int i = k; i < n - k; i++)
        {
            sum += nums[i] ;
        }
        
        sum = sum / (n - 2*k) ;
        cout << fixed << sum << setprecision(6) << endl ;
        // "fixed" is important 
        
    }
    return 0 ;
}