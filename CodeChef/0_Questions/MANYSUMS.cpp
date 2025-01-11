#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int l , r ;
        cin >> l >> r ;

        // min sum possible = l + l 
        // max sum possible = r + r 

        // for serial numbers with possible combinations between l and r 
        // we can get every sum bewteen min and max sum 

        int mn_sum = l + l ;
        int mx_sum = r + r ;
        cout << mx_sum - mn_sum + 1 << endl ;
    }
    return 0 ;
}