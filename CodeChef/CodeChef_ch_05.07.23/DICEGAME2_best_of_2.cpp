#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--)
    {
        int a = 0, b = 0 ;
        vector<int> alice(3), bob(3) ;
        for (int i = 0; i < 3; i++)
        {
            cin >> alice[i] ;
        }
        for (int i = 0; i < 3; i++)
        {
            cin >> bob[i] ;
        }

        sort(alice.begin(), alice.end()) ;
        sort(bob.begin(), bob.end()) ;

        a = alice[2] + alice[1] ;
        b = bob[2] + bob[1] ;

        if (a == b) cout << "Tie\n" ;
        else if (a > b) cout << "Alice\n" ;
        else cout << "Bob\n" ;
        
        
    }
    
    return 0 ;
}