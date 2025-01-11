#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int a, b ;
        cin >> a >> b ;
        // kay : number , value : no. of matches to make it 
        unordered_map<int, int> mp = {
            {0,6},
            {1,2},
            {2,5},
            {3,5},
            {4,4},
            {5,5},
            {6,6},
            {7,3},
            {8,7},
            {9,6}
        };

        int sum = a + b ;
        int ct = 0 ;
        while (sum > 0) {
            ct += mp[sum%10] ;
            sum /= 10 ;
        }
        cout << ct << endl ;




    }
    return 0 ;
}