/*
    Q : Given a string return  length longest common subsequence which is palindromic 
    A : LCS(s, rev(s))
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int LPS(string s1, string s2) {
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
    string s1 ;
    cin >> s1 ;
    string s2 = "" ;
    for (int i = s1.length()-1; i >= 0; i--)
    {
        s2.push_back(s1[i]) ;
    }
    // cout << s2 << endl ;
    cout << LPS(s1, s2) << endl ;
    return 0 ;
}