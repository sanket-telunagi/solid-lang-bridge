#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    return size of longest common substring 
*/

int dp[1001][1001] ;

int LCSubstring(string s1, string s2, int i , int j) {
    if ( i < 0 || j < 0) return 0 ;

    // add 1 if the the characters are same 
    if (s1[i] == s2[j]) return (1 + LCSubstring(s1, s2, i - 1, j - 1)) ;

    return 0 ;
}

int LCSubstring_memoise(string s1, string s2, int i , int j) {
    // return 0 if both string ends 
    if ( i < 0 || j < 0) return 0 ;
    

    // return dp[i][j] if it is filled 
    if (dp[i][j] != -1) return dp[i][j] ;

    // add 1 if the the characters are same 
    if (s1[i] == s2[j]) return dp[i][j] = (1 + LCSubstring_memoise(s1, s2, i - 1, j - 1)) ;

    return dp[i][j] = 0 ;
}

int LCSubstring_dp(string s1, string s2) {
    int hsh[s1.length() + 1][s2.length() + 1] ;
    int n = s1.length(), m = s2.length() ;
    int res = 0 ;
    // initialise the array 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0) hsh[i][j] = 0 ;
        }
        
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if (s1[i-1] == s2[j -1]) {
                hsh[i][j] = 1 + hsh[i-1][j-1] ;
                res = max(res, hsh[i][j]) ;
            } else {
                hsh[i][j] = 0;
            }
        }
        
    }

    // debug table
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         cout << hsh[i][j] << " " ;
    //     }
    //     cout << endl ;
        
    // }
    

    // return hsh[n][m] ;
    return res ;

    
}

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    memset(dp, -1, sizeof(dp)) ;
    // cout << LCSubstring(s1, s2, s1.length() - 1, s2.length() - 1) << endl ;
    // cout << LCSubstring_memoise(s1, s2, s1.length() - 1, s2.length() - 1) << endl ;
    for (int i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]) ;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        s2[i] = tolower(s2[i]) ;
    }
    
    cout << LCSubstring_dp((s1), s2) << endl ;



    return 0 ;
}