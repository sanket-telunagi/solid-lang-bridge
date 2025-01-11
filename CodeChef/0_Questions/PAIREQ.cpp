#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    The changes should be minimum 
    if we calculate the count of ach element and 
    choose the maximum ocuuring element to make equal to all the elemets 
    so the number of swaps will be 
    n - (mx_occurances)
*/

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        unordered_map<int, int> mp ;
        int n ;
        cin >> n ;
        int mx_ct = 0 ;
        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x ;
            mp[x]++ ;
            mx_ct = max(mx_ct, mp[x]) ;
        }

        cout << n - mx_ct << endl ;
        
    }
    return 0 ;
}