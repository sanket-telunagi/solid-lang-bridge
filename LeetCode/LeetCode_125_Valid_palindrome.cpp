#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPalindrome(string s) {
    int l =0 , r = s.length() -1 ; 


    while (l < r) {

        if (!((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= 'a' && s[l] <= 'z') || (s[l] >= '0' && s[l] <= '9'))) {
            l++ ;
            // cout << s[l] << " " << s[r] << endl ;
            continue ;
        }

        if (!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z') || (s[r] >= '0' && s[r] <= '9'))) {
            r-- ;
            // cout << s[l] << " " << s[r] << endl ;
            continue ;
        }
    
        if (tolower(s[l]) != tolower(s[r])) return false ;
            {
            l++ ;
            r-- ;
        }

    }
    

    return true ;
}

int main()
{
    string s ;
    getline(cin , s) ;
    cout << isPalindrome(s) << endl ;
    return 0 ;
}