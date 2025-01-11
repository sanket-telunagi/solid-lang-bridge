#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

long long divide(int divi, int divis) {
    long long dividend = divi , divisor = divis;
    if (divisor == 0) return INT_MAX ;
    bool isNegative = false ;
    if (dividend < 0) {
        isNegative = !isNegative ;
        dividend = abs(dividend) ;
    }
    if (divisor < 0) {
        isNegative = !isNegative ;
        divisor = abs(divisor) ;
    }
    if (divisor == 1) {
        if (isNegative) {
            return -1 * dividend ;
        } else {
            return dividend ;
        }
    }
    // cout << dividend << " " << divisor << endl ;
    long long ct = 0 ;
    while (dividend >= divisor) {
        dividend -= divisor ;
        ct++ ;
    }
    return isNegative ? -1*ct : ct  ;
}

int main()
{
    int dividend, divisor ;
    std :: cin >> dividend >> divisor ;
    cout << divide(dividend, divisor) << endl ;
    return 0 ;
}