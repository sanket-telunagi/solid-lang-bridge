#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >>t ;
    while (t--) {
        int  x, y ;
        cin >> x >> y ;
        if (x*15 >= 2 * y) cout << "YES\n" ;
        else {
            cout << "NO\n" ;
        }
    }
    return 0 ;
}