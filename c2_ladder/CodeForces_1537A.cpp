#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    we can add non-negative numbers to the array that is we can add '0' to the array 
    1. so if sum > n we just have to add '0' in the numerator for 'sum - n' times to increase count till denominator 
    2. if sum < n just add single element to make the sum equal to denominator
*/

int main()
{
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        int sum = 0 ;
        for(int i = 0 ; i< n ; i++){
            int x ;
            cin >> x ;
            sum += x ;
        }
        cout << (sum < n ? 1 : sum - n) << endl ;
    }
    return 0 ;
}