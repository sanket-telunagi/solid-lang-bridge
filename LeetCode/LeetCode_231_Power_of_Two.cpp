#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPowerOfTwo(int n) {
    if(!(n&(n-1))) return true ;
    return false ;
}

int main()
{
    int num ;
    cin >> num ;
    cout << isPowerOfTwo(num) ;
    return 0 ;
}