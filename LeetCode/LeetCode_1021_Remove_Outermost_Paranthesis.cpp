#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

string removeOuterParentheses(string s) {
    stack<char> stk ;
    bool set = false ;
    string res = "" ;
    // for(char it : s) {
    //     stk.push(it) ;
    //     if (!set) {
    //         res.push_back(stk.top()) ;

    //     }
    // }

    int bit = 0 ;

    for (char it : s) {
        
        if (it == '(') stk.push(it) ;

        if (stk.size() > 1) res.push_back(it) ;
        
        if (it == ')') stk.pop() ;

    }

    return res ;
}

int main()
{
    string s ;
    cin >> s ;
    cout << removeOuterParentheses(s) ;
    return 0 ;
}