#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        int alice, bob ;
        cin >> alice >> bob ;
        int ct = 10000 ;
        string res = "NO" ;
        while (alice != bob && ct >= 0) {
            if (alice > bob) {
                alice-- ;
                bob++ ;
            } else {
                bob-- ;
                alice += 3 ;
            }

            ct-- ;
        }

        if (alice == bob) {
            res = "YES" ;
            cout << res << endl ;
        } else {
            cout << "NO" << endl ;
        }
    }
    
    return 0 ;
}