#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--) {
        long long num ;
        cin >> num ;
        int ct = 0 ;

        vector<int> notes = {100, 50, 10, 5, 2, 1} ;

        for (auto it : notes) {
            if (num == 0) break ;
            ct += num / it ;
            num %= it ;
        }
        cout << ct << endl ;
    }
    return 0 ;
}