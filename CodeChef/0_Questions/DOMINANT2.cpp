#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        int max_el_occ = -1 ;
        unordered_map<int, int> mp ;
        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x ;
            mp[x]++ ;
            max_el_occ = max(max_el_occ, mp[x]) ;
        }

        int ct = 0 , max_el = -1 ;
        for (auto & it : mp) {
            if (it.second == max_el_occ) {
                max_el = it.first ;
                ct++ ;}
        }

        if (ct > 1) {
            cout << "NO" << endl ;
        } else {
            cout << "YES" << endl ;
        }
        
    }
    
    return 0 ;
}