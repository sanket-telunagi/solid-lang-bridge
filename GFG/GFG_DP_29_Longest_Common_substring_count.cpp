#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int LCSubstring(int i, int j, string & s1, string & s2) {
    if ( i == 0 || j == 0 ) return 0 ;

    if (s1[i-1] == s2[j-1]) return 1 + LCSubstring(i-1, j-1, s1, s2) ;
    return max(LCSubstring(i-1, j, s1, s2), LCSubstring(i, j-1, s1, s2)) ;
}

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    cout << LCSubstring(s1.length(), s2.length(), s1, s2) << endl ;
    return 0 ;
}