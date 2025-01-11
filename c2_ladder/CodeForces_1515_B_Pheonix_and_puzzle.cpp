#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isSq(long long num) {
    long long temp = sqrt(num) ;
    return temp * temp == num ;
}

int main()
{
    long long t ;
    cin >> t;
    while (t--) {
        long long num ;
        cin >> num ;
        // if (__builtin_popcount(num) == 1 && num > 1) cout << "YES\n" ;
        // else cout << "NO\n" ;

        if (num % 2 == 0) {
            if (isSq(num / 2)) cout << "YES\n" ;
            else if (isSq(num / 4) && num % 4 == 0) cout << "YES\n" ;
            else cout << "NO\n" ;
        } else cout << "NO\n" ;
    }
    return 0 ;
}