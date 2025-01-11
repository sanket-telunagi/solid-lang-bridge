/*
 match the pattern

*/  

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

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

    return hsh[n][m] ;

    
}


bool pattern_matching(string & a, string & b) {
    int n = LCS_dp(a, b) ;
    if (n == a.length()) return true ;
    return false ;
}

int main()
{
    string a, b ;
    cin >> a >> b ;
    cout << pattern_matching(a,b) << endl ;
    return 0 ;
}