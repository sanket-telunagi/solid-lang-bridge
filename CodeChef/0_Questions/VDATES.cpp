#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n , x , y ;
        cin >> n >> x >> y ;
        if (n >= x && n <= y) cout << "Take second dose now\n" ;
        else if (n < x) cout << "Too Early\n" ;
        else cout << "Too Late\n" ;
    }
    
    return 0 ;
}