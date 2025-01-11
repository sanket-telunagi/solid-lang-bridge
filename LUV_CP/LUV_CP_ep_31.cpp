// balanced paranthesis 
// stack implementation 

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
bool isBalanced(string s){

    unordered_map <char, int> symbols = {{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}} ;
    stack <char> stk ;
    for (char symbol : s){
        if(symbols[symbol] < 0) stk.push(symbol) ;
        else {
            if(stk.empty()) return false ;
            char top = stk.top() ;
            stk.pop() ;
            if((symbols[top] + symbols[symbol] != 0)) return false ;
        }
    }
    if(stk.empty()) return true ;
    return false ;
}
int main() {
    int t ;
    cin >> t ;
    while (t--)
    {
        string s ;
        cin >> s ;
        if(isBalanced(s)) cout << "YES" << endl ;
        else cout << "NO" << endl ;
    }
    return 0 ;
}