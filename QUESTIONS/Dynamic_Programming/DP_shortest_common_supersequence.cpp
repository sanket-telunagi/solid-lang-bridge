/*
    Q : Given two string return length of the minimum string that can be craeated using these 
        two string s' where s1 and s2 are the subsequence of the s'

    A : We can solve this tging using LCS 
        As we need to write the common characters only once in the sequential manner 
        write the common characters once 

    Ex : 

        s1 : geek 
        s2 : eke 

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

int SCS (string & s1, string & s2) {
    int m = s1.length() , 
        n = s2.length() , 
        L = LCS_dp(s1, s2) ;

    int res = m + n - L ;
    return res ;
}


int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    cout << SCS(s1, s2) << endl ;
    return 0 ;
}