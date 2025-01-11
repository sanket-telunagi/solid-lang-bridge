/*
    The Hamming distance between two integers is the number 
    of positions at which the corresponding bits are different.

    Given two integers x and y, return the Hamming distance between them.

    sol : 
    take xor of both elements and count the number of set bits 
*/


#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

struct custom {
    int n1 ;
    int n2 ;
};

class custom1 {
    public :
        int n1 ;
        int n2 ;
};


// ---- Using builting pop count function 
// int hammingDistance(int x, int y) {
//     int temp = x^y ;
//     return __builtin_popcount(temp) ;
// }


// ---- Using iterator 
int hammingDistance(int x , int y){
    int temp = x^y ;
    int ct = 0 ;
    while(temp){
        if (temp & 1){
            ct++ ;
        }
        temp >>= 1 ;
    }
    return ct ;
}

int main()
{
    custom1 p ;
    cin >> p.n1 >> p.n2 ;

    cout << hammingDistance(p.n1,p.n2) ;

    return 0 ;
}