#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int x, y, z ;
        cin >> x >> y >> z ;
        
        int res = 0 ;

        {
            int B = x ;
            int A = z * y ;
            if (A % B == 0 && res == 0) {
                res = 1 ;
                cout << A << " " << B << endl ;
            }

        }

        {
            int B = y ;
            int A = x * z ;
            if (A % B == 0 && res == 0) {
                res = 1 ;
                cout << A << " " << B << endl ;
            }

        }

        {
            int B = z ;
            int A = x * y ;
            if (A % B == 0 && res == 0) {
                res = 1 ;
                cout << A << " " << B << endl ;
            }

        }

        if (res == 0) cout << -1 << endl ;

    }
    
    return 0 ;
}