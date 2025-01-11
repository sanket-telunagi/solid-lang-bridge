#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ; cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        int arr[n] ;
        int lo = INT_MAX ;
        int hi = INT_MIN ;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i] ;
            if(arr[i] > hi) hi = arr[i] ;
            if (arr[i] < lo) lo = arr[i] ;
        }
        int moves = 0 ;
        int start = 0 , end = n - 1 ;
        bool lo_break = false , hi_break = true ;
        for (int i = 0; i < n / 2; i++)
        {
            if (lo_break & hi_break) break;
            if (arr[start] == lo | arr[end] == lo) {
                lo_break = true ;
            }
            if (arr[end] == hi | arr[start] == hi ) hi_break = true ;
            moves++ ;
            start++ ;
            end-- ;
        }
        cout << moves <<  endl ; ;
    }
    return 0 ;
}