#include<bits/stdc++.h>
using namespace std ;

int minority(string s) {
    int zero_count = 0, one_count = 0 ;
    for(char ch : s) {
        zero_count += ch == '0' ;
        one_count += ch == '1';
    }
    return min( zero_count, one_count) ;
}

int main () {
    int t ;
    cin >> t ;
    while (t--)
    {
        /* code */
        string s ;
        cin >> s ;

        cout << min(int((s.length() - 1)/2),minority(s) )<< endl ;
    }
    
    return 0 ;
}