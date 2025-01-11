#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        int ct = 0 ;
        while (n > 0) {
            if (n % 10 == 4) ct++ ;
            n /= 10 ;
        }
        cout << ct << endl ;
    }
    return 0 ;
}