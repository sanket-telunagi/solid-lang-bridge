#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Solving with sliding window 
    adding the the count of 'T' and 'F'every time we increase the window 
*/

int maxConsecutiveAnswers(string answerKey, int k) {
    int true_ct = 0 , false_ct = 0 , l = 0 , r = 0 , res = 0 , n = answerKey.length();

    for (int r = 0; r < n; r++)
    {
        true_ct += (answerKey[r] == 'T') ;  // add 1 if its 'T' else 0
        false_ct += (answerKey[r] == 'F') ; // add 1 if its 'F' else 0
        
        // if the minimum count exceeds the limit 
        while (min(false_ct, true_ct) > k) {
            // if true_ct is min, subtract true_ct untill its 'T'
            true_ct -= answerKey[l] == 'T' ;

            // if false_ct is min, subtract false untill its 'F'
            false_ct-= (answerKey[l] == 'F') ;

            l++ ;
        }

        // if (min(true_ct, false_ct) > k ) {
        //     if (true_ct < false_ct && true_ct > k) {
        //         while (true_ct != 0) {
        //             true_ct-- ;
        //             l++ ;
        //         }
        //     } else {
        //         while (false_ct != 0)
        //         {
        //             false_ct-- ;
        //             l++ ;
        //         }
                
        //     }
        // }
        res = max(res, r - l + 1) ;
    }
    return res ;
}

int main()
{
    string s ;
    int k ;

    cin >> s >> k ; 
    cout << maxConsecutiveAnswers(s, k) ;
    return 0 ;
}