#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isVowel(char & ch) {
    return ch == 'a' || 
           ch == 'e' || 
           ch == 'i' || 
           ch == 'o' || 
           ch == 'u' || 
           ch == 'A' || 
           ch == 'E' ||
           ch == 'I' ||
           ch == 'O' ||
           ch == 'U' ;
}

string sortVowels(string s) {
    int n = s.length() ;
    vector<char> vowels ;

    for (auto ch : s) {
        if (isVowel(ch)) vowels.push_back(ch) ;
    }

    sort(vowels.begin(), vowels.end()) ;

    int v = 0 ;
    for (int i = 0; i < n; i++)
    {
        if (isVowel(s[i])) {
            s[i] = vowels[v++] ;
        }
    }
    return s ;
}

int main()
{
    string s ;
    cin >> s ;

    cout << sortVowels(s) << endl ;
    return 0 ;
}