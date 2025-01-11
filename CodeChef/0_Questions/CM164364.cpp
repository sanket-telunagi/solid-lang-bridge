#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x ;
        cin >> n >> x ;
        unordered_map<int,int> mp ;
        for (int i = 0; i < n; i++)
        {
            int x ;
            cin >> x ;
            mp[x]++ ;
        }
        // x is always less than or equal to n
        int possible_types = n - x ;

        // 
        possible_types = min(possible_types,(int) mp.size()) ;
        cout << possible_types << endl ;
        
    }
    
    return 0 ;
}