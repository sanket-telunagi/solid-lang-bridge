#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool buddyStrings(string s, string goal) {
    int a = s.length(), b = goal.length() ;
    if (a != b) return false ;


    int ptr1 = 0 , ptr2 = 0, ct = 0 ;
    for (int i = 0; i < a; i++)
    {
        if (s[i] != goal[i]) {
            ct++ ;
            if (ct == 1) ptr1 = i ;
            else ptr2 = i ;
        }
        else {

        }
        
        if (ct > 2) return false ;  
    }
    swap(s[ptr1], s[ptr2]) ;
    if (s != goal) return false ;
    return true ;
}


int main()
{
    string a, b ;
    cin >> a>> b ;
    cout << buddyStrings(a,b) << endl ;
    return 0 ;
}