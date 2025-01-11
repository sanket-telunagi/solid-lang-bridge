#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int p ;
        cin >> p ;

        /*
        
        bool f = false ;
        for (int i = 2; i <= p; i++)
        {
            for (int j = i + 1; j <= p; j++)
            {
                if (p % i == p % j) {
                    cout<< i << " " << j << endl ;
                    f = true ;
                    break ;
                }
            }
            if (f) break; 
        }
        */

       // one of the answer will be '2' always ;
       cout << ((p-1) / 2) << " " << (p - 1) << endl ;
    
    }
    return 0 ;
}