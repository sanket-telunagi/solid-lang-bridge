#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t ;
    while (t--)
    {
        long long x , y , a, b ;
        cin >> x >> y >> a >> b ;
        b = min(b, a + a) ;
        if (x < y) {
            swap(x, y) ;
        }
        cout << (y * b + (x - y) * a) << endl ;
    }
    
    return 0 ;
}