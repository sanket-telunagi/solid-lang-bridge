/*
    binary search application : 
        1. finding square root 
        2. finding nth root 
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

double mulitply(double mid , int n) {
    double ans = 1 ;
    while (n--)
    {
        ans *= mid ;
    }
    return ans ;
}

double nthRoot(int x, int n, double esp = 1e-9) {
    double lo = 1, hi = x, mid ;
    while(hi - lo > esp) {
        mid = (lo + hi) / 2 ;
        if (mulitply(mid,n) < x) {
            lo = mid ; // make lo mid
        } else {
            hi = mid ; // make hi mid
        }
    }
    return hi;
}

double sqRoot(int x, double esp = 1e-9) {
    double lo = 1, hi = x, mid ;
    while(hi - lo > esp) {
        mid = (lo + hi) / 2 ;
        if (mid * mid < x) {
            lo = mid ; // make lo mid
        } else {
            hi = mid ; // make hi mid
        }
    }
    return hi;
}


int main() {
    int x , n;
    cin >> x >> n;
    double root = sqRoot(x) ;
    double nRoot = nthRoot(x,n) ;
    cout << setprecision(10) << root << " " << pow(x,(1.0/2)) << endl ;  // 1.0 for making it float
    cout << setprecision(10) << nRoot << " " << pow(x,(1.0/n)) ;  // 1.0 for making it float
    return 0 ;
}