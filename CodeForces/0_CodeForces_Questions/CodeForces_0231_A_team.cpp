#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    int ct = 0 ;
    while (n--) {
        int sum = 0 ;
        for (int i = 0; i < 3; i++)
        {
            int x ;
            cin >> x ;
            sum += x ;
        }

        if (sum >= 2) ct++ ;
        
    }
    cout << ct << endl ;
    return 0 ;
}