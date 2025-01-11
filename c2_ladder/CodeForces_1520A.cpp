/*
    Do not be destracted
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ;
        string s ;
        cin >> s ;
        unordered_map<char,int> mp ;
        char set = '1' ;
        for(int i = 0 ; i < n ; i++) {
            mp[s[i]]++ ;
            if((mp[s[i]] > 1) && (s[i-1] != s[i])){
                cout << "No" << endl ;
                set = '0';
                break ;
            }
        }
        if (set - '0') cout << "Yes" << endl ;
    }
    return 0 ;
}