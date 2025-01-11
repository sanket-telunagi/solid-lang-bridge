#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int joseph(int n, int k) {
    if (n == 1) return 0 ;
    return (joseph(n-1, k) + k) % n ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    cout << joseph(n,k) << endl ;
    return 0 ;
}