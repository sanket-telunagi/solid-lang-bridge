#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// unordered_map <char, int> HSH(string & str) {
//     unordered_map<char,int> ans ;
//     for (auto & ch : str) ans[ch]++ ;
//     return ans ;
// }
// vector<int> findAnagrams(string s, string p) {
//     int n = s.length();
//     int n2 = p.length() ;
//     if(n < n2) return {} ;
//     if (s == p) return {0} ;
//     vector<int> ans ;
//     unordered_map<char, int> h1 = HSH(p) ;
//     for(int i = 0 ; i <= n - n2 ; i++) {
//         string temp = s.substr(i, n2) ;
//         unordered_map<char, int> h2 = HSH(temp) ;
//         if (h1 == h2) ans.push_back(i) ;
//         h2.clear() ;
//     }
//     return ans ;
// }

vector <int> findAnagrams(string s, string p) {
    vector <int> ans , phsh(26,0), hsh(26,0);
    int window = p.length(), n = s.length() ;
    if (n < window) return ans ;
    int left = 0 ,right = 0 ;

    // creating first window
    while (right < window)
    {
        phsh[p[right] - 'a'] += 1 ;
        hsh[s[right++] - 'a'] += 1;
    }

    // starting from last window position 
    right -= 1 ;

    // sliding the window
    while (right < n) {
        // cout << left << " " << right << endl ;
        // if hash are equal then append the index
        if (phsh == hsh) ans.push_back(left) ;
        // moving window to right
        right += 1 ;
        if (right != n) hsh[s[right] - 'a'] += 1 ;
        hsh[s[left]-'a'] -= 1 ;
        left += 1 ;
    }
    return ans ;
} 

int main()
{
    string s, p ;
    cin >> s >> p ;
    for (auto & i : findAnagrams(s,p)) {
        cout << i << " " ;
    }
    return 0 ;
}