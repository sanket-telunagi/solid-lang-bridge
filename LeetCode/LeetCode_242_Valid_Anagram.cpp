#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isAnagram(string s, string t) {
        long long  temp1 [27] = {0},
       temp2 [27] = {0} ;

        for (char it : s) {
            temp1 [it -'a'] ++ ;
        } 

        for (char it : t) {
            temp2 [it -'a'] ++ ;
        } 

        for (int i = 0 ; i < 27; i++) {
            if (temp1[i] != temp2[i]) return false ;
        }

        return true ;
    }

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    cout << isAnagram(s1, s2) << endl ;
    return 0 ;
}