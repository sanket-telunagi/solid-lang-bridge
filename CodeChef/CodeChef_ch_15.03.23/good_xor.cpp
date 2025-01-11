#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        unordered_map<int,int> hsh ;
        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x ;
            hsh[x]++ ;
        }

        if (n == 1) cout << -1 << endl ;
        else {
            if (hsh[0] == hsh[1]) cout << 0 << endl ;
            else cout << abs(hsh[0] - hsh[1]) - 1 << endl ;
        }
        
    }
    return 0 ;
}