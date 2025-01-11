#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*

    We can scramble a string s to get a string t using the following algorithm:

    If the length of the string is 1, stop.
    If the length of the string is > 1, do the following:
    Split the string into two non-empty substrings at a random index, 
    i.e., if the string is s, divide it to x and y where s = x + y.
    Randomly decide to swap the two substrings or to keep them in the same order. 
    i.e., after this step, s may become s = x + y or s = y + x.
    Apply step 1 recursively on each of the two substrings x and y.
    Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, 
    otherwise, return false.
*/


unordered_map<string , bool> mp ;

bool solve (string  a , string  b) {
    if (a.compare(b) == 0) return true ;
    if (a.length() <= 1) return false ;

    string key = a + b ;

    if (mp.find(key) != mp.end()) return mp[key] ;

    int n = a.length() ;

    bool res = false ;

    for (int k = 1; k <= n - 1; k++)
    {
        // swapping 
        bool cdn1 = solve(a.substr(0,k), b.substr(n - k , k)) && solve(a.substr(k, n-k), b.substr(0, n-k)) ;
        // non swapping 
        bool cdn2 = solve(a.substr(0, k), b.substr(0, k)) && solve(a.substr(k, n - k), b.substr(k , n - k)) ;

        if (cdn1 || cdn2) {
            res = true ;
            break ;
        }
    }
    return mp[key] = res ;
}

int main()
{
    string a, b ;
    cin >> a >> b;

    cout << solve(a,b) << endl ;

    return 0 ;
}