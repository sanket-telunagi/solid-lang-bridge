#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        float s, a, b, c ;
        cin >> s >> a >> b >> c ;
        s = s + (s * 0.01 * c) ;
        if (s >= a && s <= b) cout << "Yes\n" ;
        else cout << "No\n" ;
    }
    return 0 ;
}