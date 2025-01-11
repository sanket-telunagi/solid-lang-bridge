#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    we just have to find a "NO" condition else "YES"
*/

int main()
{
    int t ;
    cin >>t ;
    while(t--) {
        int arr[4] ;
        for(int i = 0 ; i < 4 ; i++) {
            cin >> arr[i] ;
        }
        cout << (max(arr[0],arr[1]) < min(arr[2],arr[3]) | max(arr[2],arr[3]) < min(arr[0],arr[1]) ? "NO" : "YES") << endl ;
    }
    return 0 ;
}