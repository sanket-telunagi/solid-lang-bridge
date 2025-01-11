#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        int even = 0 , odd = 0 ;
        for(int i = 0 ; i < 2*n ; i++) {
            int x ;
            cin >> x ;
            x & 1 != 0 ? odd++ : even++ ;
        }
        cout << (odd==even ? "Yes" : "No") << endl ;
    }
    return 0 ;
}