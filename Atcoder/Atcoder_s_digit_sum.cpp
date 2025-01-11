#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

long long digitSum(long long num) {
    long long sum = 0 ;
    while (num > 0) {
        sum += num % 10 ;
        num /= 10 ;
    }
    return sum ;
}

long long result(long long k , long long d) {
    long long ct = 0 ;
    long long M = 1e9 + 7;
    while (k--) {
        if (k == 0) break;
        if (digitSum(k) % d == 0) {
            ct = (ct + 1) % M ;
        }
    }

    return ct  ;
}

int main()
{
    long long  k , d ;
    cin >> k >> d ;
    cout << result(k, d) << endl ;
    return 0 ;
}