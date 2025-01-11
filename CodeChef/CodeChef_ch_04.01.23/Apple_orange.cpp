#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;cin >> t ;
    while (t--)
    {
        int n , m ;
        
        cin >> n >> m ;

        // equal amount of apples ans oranges 
        if ( n == m ) cout << n << endl;
        else if(n % 2 != 0 || m & 2 != 0) cout << 1 << endl ;
        else if (((n / 2) % 2) != 0 || ((m / 2) % 2 != 0)) cout << 2 << endl ;
        
    }
    
    return 0 ;
}