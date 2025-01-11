#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        float x , y , z ;
        cin >> x >> y >> z ;
        x = x - z ;
        cout << ceil(x / y) + 1 << endl ;
    }
    return 0 ;
}