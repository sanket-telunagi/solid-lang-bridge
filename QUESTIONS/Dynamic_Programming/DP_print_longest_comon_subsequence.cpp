
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

string r = "" ;

int LCS(string s1, string s2, int i , int j) {

    // return 0 if both string ends 
    if ( i < 0 || j < 0) return 0 ;
    
    // add 1 if the the characters are same 
    if (s1[i] == s2[j]) {
        // r.push_back(s2[i]) ;
        return 1 + LCS(s1, s2, i - 1, j - 1) ;
    }

    r.pop_back() ;
    return max(LCS(s1, s2, i-1, j), LCS(s1, s2, i, j-1)) ;
}

string LCS_dp(string s1, string s2) {
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

    // fill the table
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if (s1[i-1] == s2[j -1]) {
                hsh[i][j] = 1 + hsh[i-1][j-1] ;
            } else {
                hsh[i][j] = max(hsh[i-1][j], hsh[i][j-1]);
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

    // start getting the string from last 
    string res = "" ;
    int i = n, j = m ;

    while (i > 0 and j > 0) {

        if (s1[i-1] == s2[j-1]) {
            res.push_back(s1[i-1]) ;
            // cout << hsh[i][j] << " " ;
            i-- ;
            j-- ;
        } else {

            // for non comon strings 
            // if (hsh[i][j-1] > hsh[i][j]) {
            //     j-- ;
            // } else {
            //     i-- ;
            // }
        
            // for common string
            if (hsh[i][j-1] < hsh[i][j]) {
                i-- ;
            } else {
                j-- ;
            }
        }

    }

    for (int i = 0; i < res.length() - 1; i++)
    {
        swap(res[i], res[res.length() - 1-i]) ;
    }

    return res ;
}

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    // memset(dp, -1, sizeof(dp)) ;
    // cout << LCSubstring(s1, s2, s1.length() - 1, s2.length() - 1) << endl ;
    // cout << LCSubstring_memoise(s1, s2, s1.length() - 1, s2.length() - 1) << endl ;
    cout << LCS_dp(s1, s2) << endl ;

    // cout << LCS(s1, s2, s1.length() - 1, s2.length() - 1) << endl ;
    // cout << r << endl ;

    return 0 ;
}