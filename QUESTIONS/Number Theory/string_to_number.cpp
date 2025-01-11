/*
    given a string representing decimal number
    print it decimal

*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int string2int(string s) {
    int num = 0 ;
    int i = s.length() - 1 ;
    int factor = 1 ;
    while (i >= 0) {
        
        char digit = s[i] ;
        if (digit == '-') break;
        num = num + (factor * (digit - '0')) ;
        i-- ;
        factor *= 10 ;
    }
    if(s[0] == '-') return -1*num ;  // for negative numbers 
    return num ;
}

int main()
{
    string s ;
    cin >> s ;
    cout << string2int(s);
    // or 
    // cout << s ;
    return 0 ;
}