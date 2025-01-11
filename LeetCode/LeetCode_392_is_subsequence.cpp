#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// not works as we dont have to change the relative position on the characters
bool isSubsequence2(string s, string t) {
    unordered_map<char, int> hsht ;

    for (char it : t) {
        hsht[it]++ ;
    }
    int res = s.length() ;
    for (char ch : s) {
        if (hsht[ch] >= 1) {
            res-- ;
        }
    }
    if (res == 0) {
        return true ;
    }

    return false ;
}

int help(int i , int j, string & s, string & t) {
    if (i < 0 || j < 0) return 0 ;
    int ans = help(i-1, j, s, t) + help(i, j-1, s, t) + help(i-1, j-1, s, t) + (s[i] == s[j]) ;

    return ans ;
}

bool isSubsequence3(string s, string t) {
    int ans = help(s.length(), t.length(), s, t) ;
    cout << ans << endl ;
    if (ans == s.length()) return true  ;
    return false ;
}


/*

    Ans : go from first index of 's' 
          increase the count if it is the same character in t
          and decreament n 
          if n = 0 : whole 's' is in 't'
*/
bool isSubsequence(string s , string t) {
    int res = false ;
    int n = s.length() ;
    int ct = 0 ;
    for (char ch : t) {
        if (ch == s[ct]) {
            ct++ ;
            n-- ;
        }
    }
    // cout << n << endl ;
    if (n == 0) {
        res = true ;
    }

    return res ;
}

int main()
{
    string s,t ;
    cin >> s >> t ;
    cout << isSubsequence(s, t) << endl ;
    return 0 ;
}