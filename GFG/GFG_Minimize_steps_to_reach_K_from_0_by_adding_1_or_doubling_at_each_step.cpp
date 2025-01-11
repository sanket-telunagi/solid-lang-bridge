#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int down_k (int n) {
    
    if (n <= 0) return 0 ;
    if (n & 1) return 1 +down_k(n - 1) ;
    return 1 + down_k(n / 2) ;

}


int main()
{
    int n ;
    cin >> n ;
    cout << down_k(5) << endl ;
    return 0 ;
}