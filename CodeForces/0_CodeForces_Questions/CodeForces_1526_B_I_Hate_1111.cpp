#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        long long n ;
        cin >> n ;
        if (n > 1099) cout << "YES\n" ;
        else {
            if (n >= (111 * (n % 11))) cout << "YES\n" ;
            else cout << "NO\n" ;
        }
    }
    return 0 ;
}