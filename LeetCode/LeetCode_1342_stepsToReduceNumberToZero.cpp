#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int numberOfSteps(int num) {
    int steps = 0;
    while(num != 0) {
        if(num & 1) {
            num -= 1 ;
        }
        else {
            num /= 2;
        }
        steps++ ;
    }
    return steps ;
}

int main()
{
    int n ;
    cin >> n ;
    cout << numberOfSteps(n) ;
    return 0 ;
}