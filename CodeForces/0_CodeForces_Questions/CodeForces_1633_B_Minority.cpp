#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        string s ;
        cin >> s ;
        int ct_0 = 0 , ct_1 = 0 ;
        for (char ch : s) {
            ct_0 += ch == '0' ;
            ct_1 += ch == '1' ;
        }

        cout << ((ct_0 == ct_1 || s.length() == 1) ? 0 : min(ct_0, ct_1)) << endl ;

    }
    
    return 0 ;
}