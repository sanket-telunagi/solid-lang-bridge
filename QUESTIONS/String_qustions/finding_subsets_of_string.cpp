#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void subset(string & str, string & empty, int index = 0) {
    if (index >= str.length()) {
        cout << empty << endl ;
        return ;
    }
    empty.push_back(str[index]) ;
    subset(str, empty, index + 1) ;
    empty.pop_back() ;

    subset(str, empty, index + 1) ;
}

int main()
{
    string s ;
    cin >> s;
    string cur = "" ;
    subset(s, cur) ;
    return 0 ;
}