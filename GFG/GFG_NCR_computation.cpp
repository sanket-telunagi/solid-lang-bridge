#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

const int N = 1e9 + 7 ;
long long dp[1010] ;
long long fact(int n) {
    if (n == 0 || n == 1) return 1 ;
    if (dp[n] != -1) return dp[n] ;
    long long ans = ( (n % N) * (fact(n-1) % N)) % N ;
    return dp[n] = ans ; 
}

long long nCr(int n, int r) {
    if (r > n) return 0 ;
    memset(dp, -1, sizeof(dp)) ;
    long long ans = (fact(n) / ((fact(n-r) * fact(r)))) ;
    return ans ;
}

int main()
{
    int n , r;
    cin >> n >> r ;
    cout << nCr(n, r) << endl ;
    return 0 ;
}