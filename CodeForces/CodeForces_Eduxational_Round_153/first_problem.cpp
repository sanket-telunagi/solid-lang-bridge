#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    long long t ;
    cin >> t;
    while (t--) {
        string s ;
        cin >> s ;
        if (s == "()") cout << "NO\n" ;
        else {
            
            string temp = "" ;
            for (int i = 0; i < s.length(); i++)
            {
                /* code */
                temp.push_back('(') ;
            }
            for (int i = 0; i < s.length(); i++)
            {
                /* code */
                temp.push_back(')') ;
            }

            string temp2 = "" ;

            for (int i = 0; i < s.length(); i++)
            {
                temp2 += "()" ;
            }

            cout << "YES\n" <<  ((temp.find(s) != string :: npos )?  temp2 : temp ) << endl ;

            
        }
    }
    return 0 ;
}