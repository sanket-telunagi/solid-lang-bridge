/*
    given a binary string print its decimal representaion
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

long long binary2decimal(string bin) {
    long long dec = 0 ;
    int i = 0 ;
    while(bin != "") {
        if (bin[bin.length() - 1] - '0') {
            dec += pow(2,i) ;
        }
        i++ ;
        bin.pop_back() ;
    }
    return dec ;
}

int main()
{
    string num ;
    cin >> num ;
    cout << binary2decimal(num) ;
    
    return 0 ;
}