#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int a, b , x, y ;
    cin >> a >> b >> x >> y ;
    int m = 2 * a + b , 
        r = 2 * x + y ;

        if (m == r) cout << "Equal\n" ;
        else if (m > r) cout << "Messi\n" ;
        else cout << "Ronaldo\n" ;
    return 0 ;
}