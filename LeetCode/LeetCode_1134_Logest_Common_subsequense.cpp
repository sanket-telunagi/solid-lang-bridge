#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int dp[1010][1010] ;


int fun (int i, int j, string & s1, string & s2) {
    if (i < 0 || j < 0) return 0 ;

    int ans = fun(i -1, j, s1, s2) ;

    ans = max(ans, fun(i, j-1, s1, s2)) ;

    ans = max(ans, fun(i-1, j-1, s1, s2) + int(s1[i] == s2[j])) ;
    return ans ;
}


int fun_dp (int i, int j,  string & s1, string & s2) {
    if (i < 0 || j < 0) return 0 ;
    if (dp[i][j] != -1) return dp[i][j] ;
    int ans = fun_dp(i -1, j, s1, s2) ;

    ans = max(ans, fun_dp(i, j-1, s1, s2)) ;

    ans = max(ans, fun_dp(i-1, j-1, s1, s2) + int(s1[i] == s2[j])) ;
    return dp[i][j] = ans ;
}


int longestCommonSubsequence(string & s1, string & s2) {
  
    memset(dp, -1, sizeof(dp)) ;
    // return fun(s1.length()-1, s2.length() -1, s1, s2) ;
    return fun_dp(s1.length()-1, s2.length() -1, s1, s2) ;
}

int main()
{
    string s , t ;
    cin >> s >> t ;
    cout << longestCommonSubsequence(s, t) << endl ;
    return 0 ;
}