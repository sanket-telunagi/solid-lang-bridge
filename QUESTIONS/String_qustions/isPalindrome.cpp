#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPalindrome(string & str, int l , int s = 0) {
    if (s >= l) return true ;
    if (str[s] != str[l]) return false ;
    return isPalindrome(str, --l, ++s) ;
}

int main()
{
    string s ;
    cin >> s;
    cout << isPalindrome(s, s.length()-1) << endl ;
    return 0 ;
}