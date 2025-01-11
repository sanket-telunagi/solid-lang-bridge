#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    // if (n % 2 == 0) {
    //     bool is = false ;
    //     for (int i = 2; i < n / 2; i+= 2)
    //     {
    //         // cout << i << " " << n - i << endl ;
    //         if (i % 2 == 0 && (n - i) % 2 == 0) {
    //             {
    //                 cout << "YES\n" ;
    //                 is = true ;
    //                 break;
    //             }
    //         }
    //         // if (!is) cout << "NO\n" ;
    //     }
    //     if (!is) cout << "NO\n" ;
    // } else {
    //     cout << "NO\n" ;
    // }

    cout << ((n % 2 == 0 && n > 2) ? "YES\n" : "NO\n") ;
    return 0 ;
}