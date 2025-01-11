#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t ;
    while (t--) {
        int u, v, a, s;
        cin >> u >> v >> a >> s ;
         {
            float temp = sqrt(abs(u*u - 2 * a * s)) ;
            if (temp <= v) cout << "Yes\n" ;
            else cout << "No\n" ;
        }
    }
    return 0 ;
}