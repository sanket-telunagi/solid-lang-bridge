#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given two string return the the longest common subsequence from both the strings 
    Subsequence : any ordered squence 

    return count 
*/

int dp[1001][1001] ;

int LCS(string s1, string s2, int i , int j) {

    // return 0 if both string ends 
    if ( i < 0 || j < 0) return 0 ;
    
    // add 1 if the the characters are same 
    if (s1[i] == s2[j]) return 1 + LCS(s1, s2, i - 1, j - 1) ;

    return max(LCS(s1, s2, i-1, j), LCS(s1, s2, i, j-1)) ;
}

int LCS_memoise(string s1, string s2, int i , int j) {
    // return 0 if both string ends 
    if ( i < 0 || j < 0) return 0 ;
    

    // return dp[i][j] if it is filled 
    if (dp[i][j] != -1) return dp[i][j] ;

    // add 1 if the the characters are same 
    if (s1[i] == s2[j]) return dp[i][j] = (1 + LCS(s1, s2, i - 1, j - 1)) ;

    return dp[i][j] = max(LCS(s1, s2, i-1, j), LCS(s1, s2, i, j-1)) ;
}

int LCS_dp(string s1, string s2) {
    int hsh[s1.length() + 1][s2.length() + 1] ;
    int n = s1.length(), m = s2.length() ;

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
            } else {
                hsh[i][j] = max(hsh[i-1][j], hsh[i][j-1]) ;
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
    

    return hsh[n][m] ;

    
}

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    memset(dp, -1, sizeof(dp)) ;
    // cout << LCS(s1, s2, s1.length() - 1, s2.length() - 1) << endl ;
    // cout << LCS_memoise(s1, s2, s1.length() - 1, s2.length() - 1) << endl ;
    cout << LCS_dp(s1, s2) << endl ;



    return 0 ;
}