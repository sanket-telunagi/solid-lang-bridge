#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n, m , k , x , y ;
        cin >> n >> m >> k >> x >> y ;

        bool vika_404 = true ;

        for (int i = 0; i < k; i++)
        {
            int cx, cy ;
            cin >> cx >> cy ;

            if ((abs(x - cx) + abs (x - cy)) % 2 == 0) {
                vika_404 = false ;
            }
        }

        cout << (vika_404 ? "YES\n" : "NO\n") << endl ;
         

    }
    return 0 ;
}