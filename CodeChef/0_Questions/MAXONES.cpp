#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int countOnce(string & s) 
{
    int ct = 0 ;
    for (int i = 0; i < s.length(); i++)
    {
        ct += s[i] == '1' ;
    }

    return ct ;
    
}

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        // int n ;
        // cin >> n ;
        // string s ;
        // cin >> s ;
        // if (s.length() <= 3) cout << s << endl ;
        // else {
        //     // int n = s.length() ;
        //     // for (int i = n - 1; i > 0; i--)
        //     // {
        //     //     if (s[i] == '1') continue;
        //     //     if ((s[i-1] == '0' && s[i+1] == '1') or (s[i-1] == '1' and s[i+1] == '0')) s[i] = '1' ;
                
        //     // }

        //     // cout << s << endl ;


            


        // }}

        int n ;
        cin >> n ;
        string s ;
        cin >> s ;

        for ()

    }
    return 0 ;
}