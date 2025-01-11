#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int maxVowels(string s, int k) {
    int ct = 0 , j = 0, i = 0 , n = s.length() , res = -1;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'} ;
    while (j < n) {
        
        for (char ch : vowels) {
            if (s[j] == ch) {
                ct++ ;
                // cout << ct << endl ;
                break ;
            }
        }

        if (j - i + 1 > k) {
            for (char ch : vowels) {
                if (s[i] == ch) {
                    ct-- ;
                    break ;
                }
            }
            i++ ;
        }
        res = max(res, ct) ;
        j++ ;
    }
    return res ;
}

int main()
{
    string s ;
    int k ;
    cin >> s >> k ;
    cout << maxVowels(s, k) ;
    return 0 ;
}