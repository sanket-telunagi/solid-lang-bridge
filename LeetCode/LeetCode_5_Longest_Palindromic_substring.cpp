#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int dp[1001][1001] ;

int LCSubstring(string & a, string & b, int i , int j) {

    if (i < 0 || j < 0 ) return 0 ;
    if (dp[i][j] != -1) return dp[i][j] ;
    if (a[i] == a[j]) {
        return dp[i][j] =  1 + LCSubstring(a,b, i -1, j-1) ;
    } 
    return dp[i][j] = 0 ;
}

string longestPalindrome(string s) {
    string res ;
    string rev = s ;
    reverse(s.begin(), s.end()) ;
    memset(dp, -1, sizeof(dp)) ;
    cout << LCSubstring(s, rev, s.length() - 1, rev.length()-1) ;
    return "" ;
}

int main()
{
    string s ;
    cin >> s;
    cout << longestPalindrome(s) << endl ;
    return 0 ;
}