#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Anagrams : 
        words which are formed by permutaions of its letters 
        eg :

            for : rof , orf, rfo, for

*/

string  pr(string & s , int l, int r) {
    string temp = "" ;
    for (int i= l; i <= r; i++) {
        temp.push_back(s[i]) ;
    }
    return temp ;
}

int anagramsV(string & s, string & ptr) {
    vector<int> ptrV(26, 0), cp(26, 0) ;

// creating matching vector 
    for (char ch : ptr) {
        ptrV[ch - 'a']++ ;
    }

    int k = ptr.size(), n = s.length(), res = 0;

    for (int r = 0; r < n; r++)
    {
        if ( r < k ) cp[s[r] - 'a']++ ;
        else {
            cp[s[r - k] - 'a']-- ;
            cp[s[r] - 'a']++ ;
        }
        if (cp == ptrV) res ++ ;
    }
    
    return res ;
}

int anagrams(string & s, string & ptr) {

    // creating map of ptr
    unordered_map<char, int> mp, fin ;
    for (char ch : ptr) mp[ch]++ ;

    int n = s.length(), l = 0 , res = 0 , ct = mp.size(), k = ptr.length() ;
    int lp = 0 ;
    for (int r = 0; r < n; r++)
    {
        // creating window
        while (r - l + 1 < k)
        {
            if (mp.find(s[r]) != mp.end()) {
                fin[s[r]]++ ;

                if(mp[s[r]] == 0) ct -- ;
            }
            r++ ;
        }
        if (mp.find(s[r]) != mp.end()) {
                fin[s[r]]++ ;

                if(mp[s[r]] == 0) ct -- ;
            }
        // cout << pr(s, l, r) << endl;
       
        // after forming the window 
        if (r - l + 1 == k) {
            // cout << "in loop\n" ;
            lp++ ;
            // if (ct == 0) res ++ ;
        }
        if (fin == mp) res ++ ;
        if (mp.find(s[l]) != mp.end()) {
            mp[s[l]]++ ;
            if (mp[s[l]] != 0) ct++ ;
        }
        l++ ;
        
    }

    // cout << lp << endl ;
    
    return res ;

}

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        string s , ptr ;
        cin >> s >> ptr ;

        cout << anagramsV(s, ptr) << endl;
    }
    return 0 ;
}