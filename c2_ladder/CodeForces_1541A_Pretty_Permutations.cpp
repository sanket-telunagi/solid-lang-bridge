#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--) {
        // int n ;
        // cin >> n ;
        // cout << n << " " ;
        // for (int i = 1 ; i < n ; i++) {
        //     cout << i << " " ;
        // }
        // cout << endl ;

        long n ;
        cin >> n ;

        /*
        if (n % 2 == 0) {
            for (int i = 1; i <= n -1; i += 2)
            {
                cout << i + 1 << " " << i ;
            }
            cout << endl ;
        } else {
            cout << "3 1 2 " ;
            for (int i = 4; i <= n - 1; i+=2)
            {
                cout << i + 1 << " " << i ;               
            }
            cout << endl ;
        }

        */

       long start = 1 ;
       
       if ( n % 2 != 0) {
            start = 4 ;
            cout << "3 1 2 " ;
       } 
       for (int i = start; i < n; i += 2)
       {

            cout << i + 1 << " " << i << " " ;

        /* code */
       }
       cout << endl ;
       
    }
    return 0 ;
}