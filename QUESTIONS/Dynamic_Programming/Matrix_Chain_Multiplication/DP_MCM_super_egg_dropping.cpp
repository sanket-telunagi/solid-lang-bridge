#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int dp[100][10001] ;

int fun (int e, int f) {
    if (e == 0 || e == 1) return f ;
    if (f == 0 || f == 1) return f ;
    if (dp[e][f] != -1) return dp[e][f] ;
    int ans = INT_MAX ;
    for (int k = 1; k <= f; k++)  // starts from floor 1 upto the end 
    {
        int broke = 0, NoBroke = 0  ;
        if (dp[e-1][k -1] != -1)
            broke = dp[e-1][k - 1] ;
        else { broke = fun(e -1, k - 1) ;
        dp[e-1][k -1] = broke ; }  // go down one floor from curent floor with reduced eggs 
        
        if (dp[e][f - k] != -1) broke = dp[e][f-k] ;
        else {NoBroke = fun(e, f - k) ;
        dp[e][f - k] = NoBroke ;} // look in upper remainign floor with all eggs 

        int temp = 1 + max(broke, NoBroke) ;
        ans = min(ans, temp) ;
    }
    return dp[e][f] = ans ;
}

int superEggDrop(int k, int n) {
    memset(dp, -1, sizeof(dp)) ;
    return fun(k, n) ;
}

int main()
{
    int e, f ;
    cin >> e >> f ;
    cout << superEggDrop(e, f) << endl ;
    return 0 ;
}