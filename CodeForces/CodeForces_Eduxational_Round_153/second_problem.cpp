#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    long long t ;
    cin >> t ;
    while (t--)
    {
        long long m, k , a1, a2 ;
        cin >> m >> k >> a1 >> a2;

        if (a1 >= m || (m %k <= a1 && m / k <= a2)) cout<< 0 << endl ;
        else {

            int num2 = min(m/k, a2) ;
            int num1 = min(m - k * num2, a1) ;
            int rm = m - num1 - k * num2 ;

            if (rm % k == 0) cout << rm / k << endl ;
            else if ((k - rm % k) <= num1) {
                cout << (rm / k ) << endl ;

            } else {
                cout << (rm / k ) + (rm % k) << endl ;
            }
        }
    }
    
    return 0 ;
}