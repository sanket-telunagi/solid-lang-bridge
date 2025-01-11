#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given a string s, return the number of palindromic substrings in it.

    A string is a palindrome when it reads the same backward as forward.

    A substring is a contiguous sequence of characters within the string.
*/

bool isPal(string & temp) {
    for (int i = 0; i < temp.size() / 2; i++) if(temp[i] != temp[temp.size() - i - 1]) return false ;
    return true ;
}

void genSubsets(string & s, string & empty, int & count , int index) {
    if (index == s.length()) {
        if (empty.size() != 0 && isPal(empty)) count++ ;
        cout << empty << endl ;
        return ;
    }

    genSubsets(s, empty, count, index+1) ;

    empty.push_back(s[index]) ;
    genSubsets(s,empty,count, index + 1) ;
    empty.pop_back() ;
}

int countSubstrings(string s) {
    int ans = 0 ;
    string empty = "" ;
    genSubsets(s,empty,ans,0) ;
    return ans ;
}

int main()
{
    string s ;
    cin >> s ;
    cout << countSubstrings(s) ;
    return 0 ;
}