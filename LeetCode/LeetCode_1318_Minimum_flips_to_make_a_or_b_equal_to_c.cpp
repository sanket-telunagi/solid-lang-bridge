#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int a, b , c ;
    cin >> a >> b >> c ;
    int ct = 0 , l = 32;
    for (int i = 0 ; i < 32 ; i++) {
        int a_ = a & 1 ;
        int b_ = b & 1 ;
        int c_ = c & 1 ;
        
        if (c_ == 0) {
            if (a_ == 1) {
                ct ++ ;
            } 
            if (b_ == 1) {
                ct++ ;
            }
        } else if (a_ != c_ and b_ != c_){
            ct ++ ;
        }

        a = (a >> 1) ;
        b = (b >> 1) ;
        c = (c >> 1) ;
        l-- ;
        
    }
    // int temp = a | b ;
    // while (c > 0) {
    //     bool dig1 = temp & 1 ;
    //     bool dig2 = c & 1 ;
    //     if (dig1 != dig2) {
    //         if (dig2 == 0 and dig1 == 1) {

    //         }
    //     } 

    //     c >>= 1;
    // }
    cout << ct << endl ;
    return 0 ;
}