#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        if (n == 1) cout << 1 << endl ;
        else {

        for (int i = 2; i <= n + 1; i++)
        {
            cout << i << " " ;
        }
        }

        cout << endl ;
        
    }
    return 0 ;
}