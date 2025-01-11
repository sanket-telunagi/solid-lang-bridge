#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


unordered_map<string, string> mp ;

string LCSubstring(int i, int j, string & s1, string & s2) {
    if ( i == 0 || j == 0 ) return " " ;

    string key = to_string(i) + "$" + to_string(j) ;
    if (mp.find(key) != mp.end()) return mp[key] ;

    if (s1[i-1] == s2[j-1]) return mp[key] = s1[i-1] + (LCSubstring(i-1, j-1, s1, s2)) ;
    string temp1 = LCSubstring(i-1, j, s1, s2) ;
    
    string temp2 = LCSubstring(i, j-1, s1, s2) ;

    if (temp1.length() > temp2.length()) return mp[key] = temp1 ;
    return mp[key] = temp2 ;
}

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    string res =  LCSubstring(s1.length(), s2.length(), s1, s2) ;

    reverse(res.begin(), res.end()) ;

    cout << res << endl ;
    
    for (auto it : mp) {
        cout << it.first << " : " << it.second << endl ;

    }
    return 0 ;
}