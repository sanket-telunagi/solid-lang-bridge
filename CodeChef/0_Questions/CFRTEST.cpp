#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    As he can give only one person at any given day 
    the problem reduces to find the number of unoque elements in the array 
*/

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        unordered_map<int, int> mp ;
        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x ;
            mp[x] ++ ;
        }
 
        cout << mp.size() << endl ;
        
    }
    return 0 ;
}