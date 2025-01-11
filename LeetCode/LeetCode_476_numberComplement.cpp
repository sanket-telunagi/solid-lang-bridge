/*
    The complement of an integer is the integer you get when you 
    flip all the 0's to 1's and all the 1's to 0's in its binary representation.

    For example, The integer 5 is "101" in binary and its complement is 
    "010" which is the integer 2.
    Given an integer num, return its complement.
*/

/*
    5 --> 1 0 1
    2 --> 0 1 0
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// int mask(int num) {
//     int ct = 0 ;
//     while(num){
//         ct++ ;
//         num >>= 1;
//     }
//     return ct ;
// }
// string reverse_dec2bin(int num) {
//     string binary ;
//     if(!num) binary.push_back('1') ;
//     while(num) {
//         binary.push_back('0' + !(num & 1)) ;
//         num >>= 1;
//     }
//     return binary ;
// }

// long long bin2dec(string bin) {
//     long long dec = 0 ;
//     int i = 0 ;
//     while(bin != "") {
//         if (bin[bin.length() - 1] - '0') {
//             dec += pow(2,i) ;
//         }
//         i++ ;
//         bin.pop_back() ;
//     }
//     return dec ;
// }

// int findComplement(int num) {
//     // if (num == 1 | num == 0) return !num ;
//     // int temp_mask = pow(2, mask(num) - 1) ;
//     // return num ^ (temp_mask - 1) ;
//     string rev_bin = reverse_dec2bin(num) ;
//     cout << reverse_dec2bin(num) << " " << bin2dec(rev_bin) ;
//     return bin2dec(rev_bin) ;
// }

// ------- not worked 
// int findComplement(int num) {
//     if((num & (num - 1)) == 0) {
//         return (num - 1) ;
//     }else {
//         int ct = __builtin_popcount(num) ;
//         int flipped = ( (1 << (ct + 1)) - 1 ) ^ num ;
//         return flipped ;
//     }
// }

int findComplement(int num) {
    int ans = 0 ;
    int i = 0 ;
    while(num) {
        if((num & 1)) {
            ans = ans ^ (1<<i) ;
        }
        i++ ;
        num >>= 1 ;
    }
    return ans ;
}

int main()
{
    int num ;
    cin >> num ;
    // cout << findComplement(num) ;
    // cout <<  (5 ^ (__builtin_popcount(num)+num));
    // printBinary(!num) ;
    // cout << " " ;
    // printBinary(num) ;
    cout << findComplement(num) ;
    return 0 ;
}