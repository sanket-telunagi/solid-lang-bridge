#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    vector <long long> v ;
    int t ;
    cin >> t ;
    while (t--) {
        int n , k ;
        cin >> n >> k ;
        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x ;
            v.push_back(x) ;
        }
        long long maxCandy = 0 ;
        sort(v.begin(),v.end()) ;
        while (k--) 
        {
            maxCandy += v[v.size() - 1] ;
            v.pop_back() ;
            v.push_back(v[v.size()-1] / 2) ;
            sort(v.begin(),--v.end()) ;
        }  
        cout << maxCandy << endl ;
    }
    return 0 ;
}