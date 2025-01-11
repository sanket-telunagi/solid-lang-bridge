#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    long long t ;
    cin >> t ;
    while (t--) {
        long long n ;
        cin >> n ;
        cout << max(6LL, n+1) / 2 * 5 << endl ;
    }
    return 0 ;
}