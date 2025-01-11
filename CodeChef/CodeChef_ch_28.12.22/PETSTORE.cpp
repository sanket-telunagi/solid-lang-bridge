#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

string equal(unordered_map<int,int> & mp) {
    for(auto it : mp){
        if(it.second % 2 != 0) {
            return "NO" ;
        }
    }
    return "YES" ;
}
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        int temp = 0 ;
        unordered_map<int,int> hsh ;

        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x ;
            hsh[x]++ ;
        }
        // cout << (temp == 0 ? "YES" : "NO") << endl ;
        cout << equal(hsh) << endl ;
    }
    return 0 ;
}