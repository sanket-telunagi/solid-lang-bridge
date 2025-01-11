#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int x ;
        cin >> x ;
        if (x >= 1 && x < 100) cout << "Easy\n" ;
        else if (x >= 100 && x < 200) cout << "Medium\n" ;
        else cout << "Hard\n" ;
    }
    return 0 ;
}