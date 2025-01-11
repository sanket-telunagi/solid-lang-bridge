#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;

    while (t--) {
        char grid[8][8] ;
        string res = "" ;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin >> grid[i][j] ;
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    res.push_back(grid[i][j]) ;
                }
            }
            
        }

        cout << res << endl ;
        
    }
    return 0 ;
}