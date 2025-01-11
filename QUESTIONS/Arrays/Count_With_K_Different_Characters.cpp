#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int countSubStrings(string s, int k) 
{
    unordered_map<char, int > mp ;
    int ct = 0 ,
        l = 0 ,
        r = 0 ,
        n = s.length(),
        count = 0;

    for (r = 0 ; r < n ; r++) {

        if (mp.find(s[l]) == mp.end()) count++ ;
        mp[s[r]]++ ;

        if (count == k) {
            ct++ ;
        }

        while (count > k) {
            if (mp[s[l]] == 0) count-- ;
            if (count == k) ct++;
            mp[s[l]] -- ;
            l++;
        }
    }

    return ct ;
}

int main()
{
    string s ;
    int k ;
    cin >> s >> k;
    cout << countSubStrings(s, k) << endl ;
    return 0 ;
}