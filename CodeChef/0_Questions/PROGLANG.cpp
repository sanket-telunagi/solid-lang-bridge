#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int a,b , a1, b1, a2, b2 ;
        cin >> a >> b >> a1 >> b1 >> a2 >> b2 ;

        int res = 0 ;

        if ((a1 == a and b1 == b) or (b1 == a && a1 == b)) res = 1 ;

        else if ((a2 == a and b2 == b) or (a2 == b and b2 == a)) res = 2 ;


        cout << res << endl ;
    }
    return 0 ;
}