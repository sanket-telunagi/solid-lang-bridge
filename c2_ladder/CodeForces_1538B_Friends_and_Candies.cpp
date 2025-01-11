#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isint(double num) {
    int res = true ;
    if (abs(abs(num) - abs((int)num)) > 0) res = false ;
    return res ;
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
        int x = n ;
        // as the sum value get larger than float double is chosen
        double sum = 0.0 ;

        while (x--) {
            cin >> nums[x % n] ;
            sum += nums[x % n] ;
        }

        // candies that each friend should get to equalise 
        double equiliser_candies = sum / n ; 

        if (!isint(equiliser_candies)) {
            cout << -1 << endl ;
            continue;
        } else {
            int ct = 0 ;
            for (int it : nums) if (it > (int)equiliser_candies) ct++ ;
            cout << ct << endl ;
        }

    }
    
    return 0 ;
}