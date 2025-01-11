#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        pair<int,int> a, b, f ;
        cin >> a.first >> a.second ;
        cin >> b.first >> b.second ;
        cin >> f.first >> f.second ;

        // The shortest path if obstacle is not in the way 
        int ans = abs(a.first - b.first) + abs(a.second - b.second) ;
        
        // if obstacle lies between the shortest path it takes 2 extra steps to pass the obstacle from 
        // any of the side 
        if ((a.first == b.first && a.first == f.first && min(a.second , b.second) < f.second && max(a.second, b.second) > f.second) || 
             a.second == b.second && a.second == f.second && min(a.first, b.first) < f.first && max(a.first, b.first) > f.first) 
             ans += 2 ;
        cout << ans << endl ;
    }
    return 0 ;
}