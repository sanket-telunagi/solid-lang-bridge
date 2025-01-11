#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int whichPower(long long num) {
    int ct = 0 ;
    while(num > 0) {
        if (num & 1) break ;
        ct++ ;
        num >>= 1;
    }
    return ct ;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b ;
        cin >> a >> b ;
        int ct = 0 ;
        if (a == b) cout << 0 << endl ;
        // else {
        //     if (b > a ) {
        //         if (a % 2 != 0) {
        //             while (__builtin_popcount(a) != 1) { // untill its a power of two
        //                 ct++ ;
        //                 a-- ;
        //                 a /= 2 ;
        //             }
        //         }
        //         while (b >= a && b != 1) {
        //             if ( b == a) break;
        //             b /= 2 ;
        //             ct++ ;
        //         }
        //         cout << ct << endl ;
        //     } else {
        //         if (a % 2 == 0) {
        //             while (a >= b) {
        //                 if (a == b) break ;
        //                 a /= 2 ;
        //                 ct++ ;
        //             }
        //             cout << ct << endl;
        //         } else {
        //             a = a - 1 ;
        //             while (a >= b) {
        //                 a /= 2 ;
        //                 ct++ ;
        //             }
        //             cout << ct << endl ;
        //         }
        //     }
        // }
        else {
        //     if (a < b) {
        //         if (a % 2 != 0) {
        //             while (__builtin_popcount(a) != 1) {
        //                 ct++ ;
        //                 a-- ;
        //                 a /= 2;
        //             }
        //         }

        //         int pa = whichPower(a) ,
        //             pb = whichPower(b) ;

        //         ct += pb - pa ;
        //         cout << ct << endl ;

        //     } else {
        //         while (whichPower(a) == 0) {
        //             if (a % 2 == 0) {
        //                 ct++ ;
        //                 a /= 2 ;
        //             } else {
        //                 ct++ ;
        //                 a-- ;
        //                 a /= 2 ;
        //             }
        //         }
        //         int pa = whichPower(a) ,
        //             pb = whichPower(b) ;
                
        //         ct += pa - pb ;
        //         cout << ct << endl ;
        //     }
        // }

        while (b % a != 0) {
            ct++ ;
            a /= 2;
        }
        while (b != a) {
            a *= 2 ;
            ct++ ;
        }

        cout << ct << endl ;
        }
    }

    // cout << whichPower(3) <<endl;
    
    return 0 ;
}