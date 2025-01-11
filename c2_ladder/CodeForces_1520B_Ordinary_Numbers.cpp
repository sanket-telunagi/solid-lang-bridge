#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n ;
        cin >> n ;

        // floor of n / 11 will give the answer as the numbers which are same fall in 11 custody
        // except for the first 9 
        // if (n <= 9) {
        //     cout << (n %11) << endl ;
        // }else {
        //     cout << (9 + floor(float(n) / 11)) << endl ;
        // }

        // it leaves some of the numbers 
        long long ct = 0 ;
        for (long long i = 1; i <= 9; i++)
        {
            long long temp = i ;
            while (temp <= n) {
                ct++ ;
                temp = temp * 10 + i ;
            }
        }

        // for a number it will go from 
        // 1 11 111 1111 11111 ....
        // 2 22 222 2222 22222 ....
        // 3 33 333 3333 33333 ....
        // .....
        // 9 99 999 9999 99999 ....

        // which includes all the repeated numbers 

        cout << ct << endl ;
        

    }
    return 0 ;
}