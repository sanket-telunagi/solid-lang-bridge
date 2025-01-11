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
        int ct = 0 ;
        // for (int i = 0; i < n-1; i++)
        // {
        //     if (s[i] == ':' && s[i+1] == ')') ct++ ;
        // }
        // cout << ct << endl ;;

        // int i = 0 ;
        // while (i < n)
        // {
        //     if (s[i] == ':') {
        //         int j = i + 1;
        //         while (j < n) {
        //             if (s[j] == ')') {
        //                 j++ ;
        //             }
        //             if (s[j] == '('){
        //                 i - j - 1;
        //                 break ;
        //             }

        //             if (s[j] == ':') {
        //                 if (s[j-1] == '(') {
        //                     ct++ ;

        //                 }
        //             }
        //         }
        //         i = j - 1;
        //         break ;
        //     }
        //     i++ ;
        // }
        // cout << ct << endl ;

        int l = 0 , r = 0 ;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ':' && (i+1 < n) && s[i+1] == ')') {
                l = i ;
                r = l + 1 ;
                while (s[r] == ')') {
                    r++ ;
                }
                if (s[r] == ':') {
                    ct++ ;
                } else {
                    i = r - 1 ;
                }
            }

        }
        cout<< ct << endl ;;
    }
    return 0 ;
}