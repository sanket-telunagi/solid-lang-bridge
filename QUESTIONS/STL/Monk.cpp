#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    int t ;
    cin >> t ;
    while (t--)
    {
        int n, k;
        cin >> n >> k ;
        multiset <long long> candiBags ;
        for(int i = 0 ; i < n ; i++){
            long long x ;
            cin >> x ;
            candiBags.insert(x);
        }

        long long maxCandy = 0 ;
        {
            auto last = --candiBags.end() ;
            long long cnt = *last ;
            maxCandy += cnt ;
            candiBags.erase(last) ;
            candiBags.insert(cnt/2) ;
        }
        cout << maxCandy << endl ;
    }
    
    return 0 ;
}