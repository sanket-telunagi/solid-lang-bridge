#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// In case if given step is more then required step then the extra step one covers in horizontal 
// and vertical direction should be cover one more times so as to reach the required destination. 
// hence extra step is 2 times of (k-s) then it must divisible by 2.

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int a,b,c,d,k ;
        cin >> a >> b >> c >> d >> k ;
        int total_steps = abs (a-c) + abs (b - d) ;
        // x1 , y1 , x2, y2
        // if ( k == total_steps) cout << "Yes\n" ; // definately reach in k steps 
        // else if ( k < total_steps) cout << "No\n" ; // as the min required steps less, exact k step condition not matches
        if ( total_steps <= k && (total_steps - k) % 2 == 0) cout << "Yes\n" ; 
        // if the total steps are less than k, then extra steps can be added by passing either of side by 2 steps 
        // hence if the remaining steps are in multiple of two then only it can be completed in steps of k 
        else cout << "No\n" ; 
    }
    return 0 ;
}