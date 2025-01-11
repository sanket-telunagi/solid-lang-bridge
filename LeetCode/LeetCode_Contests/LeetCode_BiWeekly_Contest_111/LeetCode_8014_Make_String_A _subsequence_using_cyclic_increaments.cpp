#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool solve (int i , int j, string & a, string & b) {
    if (j < 0) return true ;
    if (i < 0 ) return false ;

    if (a[i] == b[j]) return solve(i-1, j-1, a, b) ;

    bool ans = false ;

    ans |= solve(i-1, j, a, b) ;
    
    return ans ;
}

int lcs(string s1, string s2, int i , int j) {

    // return 0 if both string ends 
    if ( i < 0 || j < 0) return 0 ;
    
    // add 1 if the the characters are same 
    if (s1[i] == s2[j]) return 1 + lcs(s1, s2, i - 1, j - 1) ;

    int ans = 0 ;

    

    for (int pt = 0 ; pt < s1.length(); pt++) {
         char ch = s1[s1.length() - 1 - pt] ;

         s1[s1.length() - 1 - pt] = char((((ch - 'a')+ 1) % 26) + 'a') ;

         ans = max(lcs(s1, s2, i-1, j), lcs(s1, s2, i, j-1)) ;

        s1[s1.length() - 1 - pt] = ch;

    }

    return ans ;
}

bool canMakeSubsequence(string str1, string str2) {
    
    if (lcs(str1, str2,str1.length() - 1, str2.length() - 1) == str2.length()) return true ;

    for (int i = 0; i < str1.length(); i++)
    {

        string temp = str1 ;
        char ch = temp[str1.length() - 1 - i] ;
        cout << ((ch - 'a') % 26) << " " << char((((ch - 'a')+ 1) % 26) + 'a')  << endl ;

        temp[str1.length() - 1 - i] = char((((ch - 'a')+ 1) % 26) + 'a') ;
        cout << temp << endl ;;

        if (lcs(temp, str2,str1.length() - 1, temp.length() - 1) == str2.length()) return true ;
    }
    return false ;
}

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    cout << canMakeSubsequence(s1, s2) ;
    return 0 ;
}