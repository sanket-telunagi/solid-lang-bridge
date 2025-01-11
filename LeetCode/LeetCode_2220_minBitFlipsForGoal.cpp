#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int minBitFlips(int start, int goal) {
    int ct = 0 ;
    int temp = start ^ goal ;
    // using XOR the count of 1 will give ans
    // as if bits are same XOR = 0 so any different bit will be flipped
    while(temp) {
        if(temp & 1) {
            ct++ ;
        }
        temp >>= 1 ;
    }
    return ct ;
}


int main()
{
    int n , k ;
    cin >> n >> k ;
    cout << minBitFlips(n,k) ;
    return 0 ;
}