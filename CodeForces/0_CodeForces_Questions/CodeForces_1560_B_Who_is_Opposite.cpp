#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int a, b, c ;
        cin >> a >> b >> c ;

        if (c > (2 * (abs(a - b)))) cout<< -1 << endl ;
        else {
            int temp = abs(a - b) ;
            if (c + temp == a || c + temp == b || a > 2 * temp || b > 2 * temp) cout << -1 << endl ;
            else {
                if ( c + temp > 2 * temp) cout << (c + temp) % (2 * temp) << endl ; 
                else cout << c + temp << endl ;
            }
        }
    }
    return 0 ;
}