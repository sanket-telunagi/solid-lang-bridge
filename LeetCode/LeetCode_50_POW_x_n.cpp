#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

double myPow(double x, int n) {
    double ans = 1 ;
    for (int i = 0; i < n; i++)
    {
        ans *= x ;
    }
    if (n >= 0) return ans ;
    else return (1/ans) ;
}

int main()
{
    double x ;
    int  n;
    cin >> x >> n ;
    // cout << fixed << setprecision(5) << myPow(x,n) ;
    cout << (1/(4)) << endl ;
    return 0 ;
}