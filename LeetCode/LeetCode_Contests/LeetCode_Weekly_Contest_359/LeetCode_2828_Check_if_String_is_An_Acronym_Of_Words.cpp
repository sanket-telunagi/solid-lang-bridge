#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isAcronym(vector<string>& words, string s) {
    string cmp = "" ;
    for (auto & word : words) {
        if (word.size() == 0) continue ;
        cmp.push_back(word[0]) ;
    }
    // cout << cmp << endl ;
    return cmp == s ;
}

int main()
{
    int n ;
    cin >> n ;
    string s ;
    cin >> s;
    vector<string> words(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i] ;
    }

    cout << isAcronym(words, s) << endl ;
    
    return 0 ;
}