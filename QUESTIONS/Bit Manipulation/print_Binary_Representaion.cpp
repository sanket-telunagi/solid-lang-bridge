/*
    given an integer num print it binary
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// prints in reverse order
string printBinary(int num) {
    string binary ;
    if(!num) binary.push_back('0') ;
    while(num) {
        cout << (num & 1) ;
        binary.push_back('0' + !(num & 1)) ;
        num >>= 1;
    }
    cout << endl ;
    return binary ;
}

int main()
{
    int num ;
    cin >> num ;
    cout << printBinary(num) ;
    return 0 ;
}