#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        string s ;
        cin >> s ;

        /*
            PLink : https://www.codechef.com/LP1TO205/problems/EVENSPLIT

            Honestly,  I am not able to understand the lexicographical order defined 
            But the observation says that sorting always works 
            except for the case of all the characters are same or the length of string is <= 2
            As the the corner case itself given in example testcase

            I am taking risk here 




            it works
        */

        if (n <= 2) cout << s << endl ;

        else {
            sort(s.begin(), s.end()) ;
            cout << s << endl ;
        }

    }
    return 0 ;
}