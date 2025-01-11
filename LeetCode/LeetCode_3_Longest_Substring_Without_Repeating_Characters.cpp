/*
    Given a string s, find the length of the longest 
    substring without repeating characters.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int lengthOfLongestSubstring(string s) {
    // int ans = INT_MIN ;
    // int ct = 0 ;
    // unordered_map<char,int> mp ;
    // for (int i = 0; i < s.length(); i++)
    // {
    //     mp[s[i]]++ ;
    //     if (i == 0) ct++ ;
    //     // ct++ ;
    //     else {
    //         if(s[i] != s[i-1] && (mp[s[i]] == 1)) {
    //             ct++ ;
    //         }else {
    //             ct = 0 ;
    //             mp[s[i]] = 0 ;
    //         }
    //     }
    //     ans = max(ans, ct) ;
    // }
    // return ans ;

    int ct = 0 ;
    unordered_map<char,int> mp ;
    int l = 0 , n = s.length();
    int r = 0 ;
    while (r < n)
    {
        mp[s[r]]++ ;
        // if the window size equals to the size of map 
        // which eventually means that the map conatines all unique elements 
        if (mp.size() == r - l + 1) {
            // cout << s.substr(l, r+1) << endl  ;
            ct = max(ct, r - l + 1) ;
            r++ ;
        } else if (mp.size() < r - l + 1) {
            while (mp.size() < r - l + 1) {
                mp[s[l]] -- ;
                if(mp[s[l]] == 0) {
                    mp.erase(s[l]) ;
                }
                l++ ;
            }
            r++ ;
        }
    }
    return ct ;
    
}

int main()
{
    string s ;
    cin >> s ;
    cout << lengthOfLongestSubstring(s) ;
    return 0 ;
}