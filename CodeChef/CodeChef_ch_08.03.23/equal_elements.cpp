#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        unordered_map<int,int> hsh ;
        int ct = 0 ;
        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x ;
            hsh[x]++ ;
            if (hsh[x] > ct) ct = hsh[x] ;
        }
        cout << n - ct << endl ;
        
        
    }
    return 0 ;
}