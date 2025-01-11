/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isValid(string s) {
    stack<char> stk ;
    unordered_map<char,int> symbols = {{'(',-1},{')',1},{'[',-2},{']',2},{'{',-3},{'}',3}} ;
    for(char i : s) {
        if(symbols[i] < 0) stk.push(i) ;
        else {
            if(stk.empty()) return false ;
            char top = stk.top() ;
            stk.pop() ;
            if (symbols[top] + symbols[i] != 0 ) return false ;  // if brackets are not matching
        }
    }
    if(stk.empty()) return true;
    return false ;
}

int main() {
    string s ;
    cin >> s;

    cout << isValid(s) ; 
    return 0 ;
}