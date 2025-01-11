#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n, a, b, c ;
        cin >> n >> a >> b >> c ;
        if (b >= n && a + c >= n) cout << "YES\n" ;
        else cout << "NO\n" ;
    }
    return 0 ;
}