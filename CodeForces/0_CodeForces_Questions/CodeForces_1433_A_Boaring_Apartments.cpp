#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >>t ;
    while (t--) {
        int nums [] = {

            1, 11, 111, 1111,
            2, 22, 222, 2222,
            3, 33, 333, 3333,
            4, 44, 444, 4444,
            5, 55, 555, 5555, 
            6, 66, 666, 6666,
            7, 77, 777, 7777,
            8, 88, 888, 8888,
            9, 99, 999, 9999
        } ;

        int n ;
        cin >> n ;
        int ct = 1 , sum = 0 ;
        for (int i = 0; i < 36; i++)
        {
            sum += ct ;
            if (ct == 4) ct = 0 ;
            if (nums[i] == n) break ;

            ct++ ;
        }
        cout << sum << endl ;
    }
    return 0 ;
}