#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPowerOfFour(int n) {
        if (n & n-2 == 0){
            return true ;
        }else {
            return false ;
        }
    }

int main()
{
    int num ;
    cin >> num ;
    cout << isPowerOfFour(num) ;
    return 0 ;
}