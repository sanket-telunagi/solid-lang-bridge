/*
    Question on advance backtracking
    Create all possible combinations of paranthesis

    for n = 2 : => two opening brackets '(' and two closing brackets ')'
        possibilities : 
            
            ()()
            (())

        tree :

                ''  : start
                 |
                 (
                / \
               (( ()
                |  \
               (()  ()(
                |    \ 
              (())    ()()   : Possibilities
    
    n = 3 ==> 

        ()()()
        ((()))
        (())()
        ()(())
        (()())

    tree : 
                 ''  : start
                 |
                 (
                / \
               /   \
              /     \
             ((      ()
            /  \       \
           /    \       \
          /      \       \
         /        \       \
      (((         (()      ()(
       |         /  \      /  \
     ((()    (()(  (())  ()()  ()((
       |      |      |    |      |
     ((())  (()()  (())( ()()( ()(()
       |      |      |    |      |
    ((())) (()()) (())() ()()() ()(())   : possibilities

*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<string> valid ;

void generateParanthesis(string s, int open, int close) {
    
    // stop when all paranthesis are consumed
    if (open == 0 && close == 0){
        valid.push_back(s) ;
        return ;
    }

    if (open > 0) {
        s.push_back('(') ;
        generateParanthesis(s,open - 1,close) ;
        s.pop_back() ; // undo changes 
    }

    if (close > 0) {
        if (open < close){ // no of open paranthesis in string is greater than closed
            s.push_back(')') ;
            generateParanthesis(s,open,close - 1) ;
            s.pop_back() ;
        }
    }


}

int main() {
    int n ;
    cin >> n ;
    generateParanthesis("",n,n) ;
    for (auto it : valid) {
        cout << it << endl ;
    }
    return 0 ;
}