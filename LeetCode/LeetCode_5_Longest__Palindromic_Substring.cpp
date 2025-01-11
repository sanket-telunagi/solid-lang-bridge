#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPal(string & s, int l, int r) {
    int n = s.length() ;
    while(l <= r) {
        if (s[l++] != s[r--]) return false ;
    }
    return true ;
}

string longestPalindrome(string s) {
    
    int l = 0 , n = s.length() ;
    int res = 0 , st = 0;

    for (int r = 0; r < n; r++)
    {
        if (isPal(s, l, r)) {
            if (r - l  + 1 > res) {
                res = r - l + 1 ;
                st = l ;
            }
        }
        while (!isPal(s, l, r)) {
            l++ ;
        }
    }
    
    return s.substr(st, res) ;
}

int main()
{
    string s ;
    cin >> s ;

    cout << longestPalindrome(s) << endl ;
    
    return 0 ;
}