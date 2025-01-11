#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int solve(int num, vector<int> & p) {
    p.push_back(num) ;
    if (num <= 1) return 0 ;
    if (num & 1) return solve((num - 1)/ 2, p) + 1 ;
    return solve(num/ 2, p) + 1 ;
}

int main()
{
    int q ;

    cin >> q ;
    while (q--) {
        int u, v ;
        cin >> u >> v ;
        // cout << 
        // cout << u << v << endl ;
        vector<int> p1, p2 ;
        int d1 = solve(u, p1) ;
        int d2 = solve(v, p2) ;

        // for (auto i : p1) cout << i << " " ;
        // cout << endl ;
        // for (auto i : p2) cout << i << " " ;
        // cout << endl ;

        // finding first common 
        int comm ;
        reverse(p1.begin(), p1.end()) ;
        reverse(p2.begin(), p2.end()) ;

        // int ptr1 = 0 , ptr2 = 0 ;

        for (int i =0 ; i < min(p1.size(),p2.size()) ; i++) {
            if (p1[i] != p2[i]) {
                break;
            }
            comm = p1[i] ;
        }

        // while (ptr1 < p1.size() and ptr2 < p2.size()) {
        //     if (p1[ptr1] == p2[ptr2]) {
        //         comm = p1[ptr1] ;
        //         break;
        //     }
        //     if (ptr1 < p1.size()) ptr1-- ;
        //     if (ptr2 < p2.size()) ptr2-- ;
        // }

        // cout << d1 << endl ;
        // cout << comm << endl ;

        // find distance from common node 
        int dc = solve(comm, p1) ;

        int res = d1 + d2 - 2 * dc ;
        cout << res << endl ;
    }
    return 0 ;
}