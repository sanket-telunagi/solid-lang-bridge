#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        vector <int> v ;
        while(n--){
            int x ;
            cin >> x ;
            v.push_back(x) ;
        }

        if((accumulate(v.begin(),v.end(),0) / n )== 1){
            cout << 0 << endl ;
        }
        else {
            cout << n - accumulate(v.begin(), v.end() , 0) << endl ;
        }
    }
    return 0 ;
}