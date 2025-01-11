#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool rotateString(string s, string goal) {
        int n = s.length() ;

        while (n--) {
            for (int i = 0; i < s.length() - 1; i++) {
                swap(s[i], s[i+1]) ;
            }

            if (s == goal) return true ;
        }

        return false ;
    }

int main()
{
    string a, b ;
    cin >> a >> b ;
    cout << rotateString(a, b) << endl;
    return 0 ;
}