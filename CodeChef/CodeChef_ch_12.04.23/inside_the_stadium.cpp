#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ; 
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        int balls = 0 ;
        float total = 0 ;
        int ct = 0 ;
        for (int i = 0; i < n; i++)
        {
            int run ;
            cin >> run ;
            total += run ;
            int rate = (total / ++balls) * 100 ;
            // cout <<total << " " <<  rate << endl ;
            if (rate == 100) ct++ ;
        }
        cout << ct << endl ;
        
    }
    return 0 ;
}