/*
    We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".
    Given a string word, return true if the usage of capitals in it is right.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool detectCapitalUse(string word) {

    int cap_count = 0 , small_count = 0 , odd_case = 0 ;
    for (int i = 0; i < word.length(); i++)
    {
        if((word[i] >= 'A' && word[i] <= 'Z')) {
            cap_count++ ;
            if(i == 0) odd_case++ ;
        }
        else if((word[i] >= 'a' && word[i] <= 'z')) {
            small_count++ ;
            odd_case++ ;
        }
        else break ;
    }
    if(cap_count == word.length() || small_count == word.length() || (odd_case) == word.length()) return true ;
    else return false ;
}

int main()
{
    string s ;
    cin >> s;
    cout << detectCapitalUse(s) ;
    return 0 ;
}