/*
    Q : Given two string print the shortest common subseqeunce 
        of which both the given strings are subsequence 
    
    A : Use the table and go from last element to the first element 
*/


#include<bits/stdc++.h>
#include <iostream>
using namespace std ;



string print_SCS (string & s1, string & s2) {
    
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

    for (int i = 0; i <= n ; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << hsh[i][j] << " " ;
        }
        cout << endl ;
    }
    

    // use the table 
    string res = "" ;

    int i = n , j = m ;
    while (i > 0 && j > 0) 
    {

        if (s1[i-1] == s2[j-1]) {
            res.push_back(s1[i-1]) ; // push anyone character
            i-- ;
            j-- ;

            cout << i << " " << j  << " " << hsh[i][j] << " " << s1[i] << " " << s2[j] << endl;
        } else {

            // move to maximum 
            // if (hsh[i][j-1] > hsh[i-1][j]) {
            //     res.push_back(s2[j-1]) ;
            //     j -- ;
            //     cout << i << " " << j  << " " << hsh[i][j] << endl;
            // } 
            // else if (hsh[i-1][j] > hsh[i][j-1]) {
            //     res.push_back(s1[i-1]) ;
            //     i-- ;
            //     cout << i << " " << j  << " " << hsh[i][j] << endl;
            // }

            // for common string
            if (hsh[i][j-1] <= hsh[i-1][j]) {
                res.push_back(s1[i-1]) ;
                i-- ;
            } else {

                res.push_back(s2[j-1]) ;
                j-- ;
            }
        }

    }

    // now add the remaining characters 
    while (i > 0)
    {
        res.push_back(s1[i--]) ;
    }

    while (j > 0)
    {
        res.push_back(s2[j--]) ;
    }
    
    return res ;

}


int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    cout << print_SCS(s1, s2) << endl ;
    return 0 ;
}