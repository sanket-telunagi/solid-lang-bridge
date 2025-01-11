#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

string largestOddNumber(string res) {
        // int res = 0 ;

        // for (char it : num) {
        //     int n = it - '0' ;
        //     if (n & 1) {
        //         res = max(res, n) ;
        //     }
        // }

        // any number ending with odd is odd

        while (res != "") {
            int n = res[res.length() - 1] - '0' ;
            if (n & 1) {
                return res ;
            } else {
                res.pop_back() ;
            }
        }

        return res  ;
    }

int main()
{
    string s ;
    cin >> s ;
    cout << largestOddNumber(s) << endl ;
    return 0 ;
}