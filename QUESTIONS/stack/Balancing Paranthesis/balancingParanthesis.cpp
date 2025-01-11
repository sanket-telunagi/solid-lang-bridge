/*
    Given a string of paranthesis print "Yes" if balanced else print "No"
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

int main() {
    string s ;
    cin >> s ;

    stack <char> stk ;
    unordered_map<char,int> symbols = {{'(',-1},{')',1}} ;
    int cnt = 0 ;
    for( char bracket : s){
        if (symbols[bracket] < 0) {stk.push(bracket) ; }
        else {
            // if(stk.empty()) return false ;
            char top = stk.top() ;
            stk.pop() ;
            
            if (!stk.empty() && (symbols[top] + symbols[bracket] != 0)) { 
                cout << "No1"; 
                break ;
            }
        }
    }


    if(stk.empty()) cout << "Yes" ;
    else cout << "No" ;

    return 0 ;
}