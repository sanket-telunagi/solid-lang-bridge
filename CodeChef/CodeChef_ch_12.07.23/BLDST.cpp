#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n , m ;
        cin >> n >> m ;
        int sum = 0 ;
        for (int i = 0; i < m; i++)
        {
            int x ;
            cin >>x ;
            sum += x ;
        }

        cout << sum % n << endl ;
        
    }
    return 0 ;
}