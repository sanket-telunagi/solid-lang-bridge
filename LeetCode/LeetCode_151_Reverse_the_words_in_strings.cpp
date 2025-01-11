#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

string reverseWords(string s) {
    string res = "" ;

    string temp = "" ;
    for (int i = s.length() - 1 ; i >= 0; i--) {

        temp.push_back(s[i]) ;
        // cout << temp << endl ;

        if (s[i] == ' ' || i == 0) {
            if (temp.back() == ' ')
                temp.pop_back() ; // pop out the ' ' char

            reverse(temp.begin(), temp.end()) ;
            res += temp + " " ;
            temp = "" ;
        }

    }

    return res ;
        
}

int main()
{
    string s ;
    // cin.ignore() ;
    getline(cin, s) ;
    cout << reverseWords(s) << endl ;
    return 0 ;
}