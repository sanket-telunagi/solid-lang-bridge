#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// vector<string> dp(1e4, "") ;
// vector<string> permutations ;
// string permute (string & s1, int l,  int index = 0) {
//     if (index >= l) {
//         permutations.push_back(s1) ;
//         return s1;
//     }
//     if (dp[index] != "") return dp[index] ;
    
//     for (int i = index ; i < l ; i++) {
//         swap(s1[index], s1[i]) ;
//         dp[index] = s1 ;
//         permute(s1, l , index + 1) ;
//         swap(s1[index], s1[i]) ;
//     }
//     cout << dp[index]<< endl  ;
//     return dp[index];
// }

// bool isSubstring(string & s1, string & s2)
// {
//     int M = s1.length();
//     int N = s2.length();
 

//     for (int i = 0; i <= N - M; i++) {
//         int j;
//         for (j = 0; j < M; j++)
//             if (s2[i + j] != s1[j])
//                 break;
//         if (j == M)
//             return true;
//     }
//     return false;
// }

// unordered_map <char, int> createHSH(string & str) {
//     unordered_map <char, int> hsh ;
//     for (char & ch : str) hsh[ch]++ ;
//     return hsh ;
// }

vector <int> createHSH(string & str) {
    vector <int> hsh (26,0) ;
    for (char & ch : str) hsh[(ch - 'a')]++ ;
    return hsh ;
}

unordered_map<char, int> HSH(string & str) {
    unordered_map <char, int> hsh ;
    for (auto & it : str) hsh[it]++ ;
    return hsh ;
}

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false ;
    if (s1 == s2) return true ;
    // permute(s1, s1.length()) ;
    // for (auto & str : permutations) {
    //     if (isSubstring(str, s2)) 
    //     // if (s2.find(str) != string::npos)
    //     {
    //         return true ;
    //     }
    // }
    // return false ;

    // # s1 hsh 
    int ls1 = s1.length() ;
    // vector <int> hsh1 = createHSH(s1) ;
    unordered_map <char , int> h1 = HSH(s1) ;
    for (int i = 0; i <= (s2.length() - s1.length()); i++)
    {
        string temp = s2.substr(i, ls1) ;
        // vector <int> hsh2 = createHSH(temp) ;
        unordered_map <char, int> h2 = HSH(temp) ;
        if (h1 == h2) return true ;
    }
    return false ;
}

int main()
{
    string s1, s2 ;
    cin >> s1 >> s2 ;
    cout << checkInclusion(s1, s2) << endl ;
    return 0 ;
}