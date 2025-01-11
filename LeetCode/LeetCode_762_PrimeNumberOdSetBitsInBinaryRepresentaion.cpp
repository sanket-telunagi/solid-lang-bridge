/*
    Given two integers left and right, 
    return the count of numbers in the inclusive range [left, right] 
    having a prime number of set bits in their binary representation.

    Recall that the number of set bits an integer has is 
    the number of 1's present when written in binary.

    For example, 21 written in binary is 10101, which has 3 set bits.

    sol :
        
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

class node {
    public :
        int n1,n2 ;
};

bool isPrime(int num) {
    if (num == 1) return false ;
    for (int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) {
            return false ;
        }
    }
    return true ;
}

int countPrimeSetBits(int left, int right) {
    int prime_bits_ct = 0 ;
    for (int i = left; i <= right; i++)
    {
        if(isPrime(__builtin_popcount(i))) {
            cout << i << " " << __builtin_popcount(i) << endl ;
            prime_bits_ct++ ;
        }
    }
    return prime_bits_ct ;
}

int main()
{
    node limit ;
    cin >> limit.n1 >> limit.n2 ;
    cout << countPrimeSetBits(limit.n1, limit.n2) ;
    return 0 ;
}