#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    int t ;
    cin >> t ;
    while (t--) {
        int n , m ;
        cin >> n >> m ;
        multiset <int> sn,sm ;
        for(int i = 0 ; i < n ; i++) {
            int x ; 
            cin >> x ;
            sn.insert(x) ;
        } 
        for(int i = 0 ; i < m ; i++) {
            int x ; 
            cin >> x ;
            sm.insert(x) ;
        } 
        for(auto it : sm) {
            if (sn.find(it) != sm.end()) cout << "YES" << endl ;
            else cout << "NO" << endl ;
        }
        
    }
    return 0 ;
}