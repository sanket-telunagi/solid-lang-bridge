/*
    A MCM problem 

    Q : Given a string s, partition s such that every 
        substring
        of the partition is a 
        palindrome

        Return the minimum cuts needed for a palindrome partitioning of s.


    Answer : 

        1. i = 1 j = size - 1
        2. k = k + 1
        3. bc : i >= j
*/


#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPalindrome(string & s, int i , int j) {
    // cout << s << endl ;
    // for (int k = i ; k <= j ; k++) {
    //     cout << s[k] ;
    // }
    // cout << endl ;
    while (i <= j) {
        if (s[i++] != s[j--]) return false ;
    }
    return true ;
}

unordered_map<string, int> mp ;

/*
    int dp [2010] ;
int fun(string & s , int i, int j) {
    if (i >= j) return 0 ;
    if (isPalindrome(s, i, j)) return 0 ;
    // cout << i << " " << j << endl ;
    if (dp[i] != -1) return dp[i] ;
    // string key = to_string(i) + " " + to_string(j) ;
    // if (mp.find(key) != mp.end()) return mp[key] ;

    int ans = INT_MAX ;

    for (int k = i; k <= j-1; k++)
    {
        if (isPalindrome(s, i, k)) {
            int temp = fun(s, k+1, j) + 1 ;
            ans = min(ans, temp) ;
        }
    }
    
    // return mp[key] =  ans ;
    return dp[i] = ans ;
}
*/

int fun(string & s , int i, int j) {
    if (i >= j) return 0 ;
    // cout << i << " " << j << endl ;
    string key = to_string(i) + " " + to_string(j) ;
    if (mp.find(key) != mp.end()) return mp[key] ;

    if (isPalindrome(s, i, j)) return 0 ;

    int ans = INT_MAX ;

    for (int k = i; k <= j-1; k++)
    {
        string nKey = to_string(i) + " " + to_string(k) ;
        string mKey = to_string(k+1) + " " + to_string(j) ;

        int left = 0 ;
        int right = 0 ;

        if (mp.find(nKey) != mp.end()) left = mp[nKey] ;
        else left = fun(s, i, k ) ;

        if (mp.find(mKey) != mp.end()) right = mp[key] ;
        else right = fun(s, k + 1, j) ;

        int temp = 1 + left + right ;
        ans = min(ans, temp) ;
    }
    
    return mp[key] =  ans ;
}


int minCut(string s) {
    return fun(s, 0, s.length()-1) ;
}

int main()
{
    string s ;
    cin >> s ;
    // cout << isPalindrome(s, 0, s.length() -1 ) << endl ;
    cout << minCut(s) << endl ;
    return 0 ;
}