#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int minFlipsMonoIncr(string s) {
    int ans = 0, ct = 0;
    for (char & i : s) {
        if (i == '0') ans = min(ans + 1, ct);
        else ct++;
    }
    return ans;
}

int main()
{
    string s ;
    cin >> s ;
    cout << minFlipsMonoIncr(s) << endl ;
    return 0 ;
}

/*
int minFlipsMonoIncr(string s) {
    int ans = 0 , start = 0 , end = s.length() - 1;
    int i = 0 ; 
    while (start <= end) {
        if (s[start] == '1' && s[end] == '0') {
            swap(s[start], s[end]) ;
            ans++ ;
        }
        if (s[end] == '1') end-- ;
        if (s[start] == '0') start++ ;
    }
    return ans ;
}
*/

/*

    int minFlipsMonoIncr(string s) {
    int ones = 0 , one_flips = 0 , zero_flips = 0 ;
    int ans = 0 ;

    // count no of ones
    for (char & i : s) i == '1' ? ones++ : 0 ;
    int temp = ones ;
    
    // count one flips 
    for (int i = s.length() - 1; i >= 0; i--)
    {

        if (s[i] == '0' && ones > 0) {
            one_flips++ ;
            continue;
        }
        else {
            if (ones == 0 ) break;
            else {
                ones-- ;
            }
        }
    }

    // count zero flips
    int end = s.length() - 1 ;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[end] == '1') end-- ;
        if (s[i] == '1' && temp > 0 && i <= end) {
            zero_flips++ ;
            temp-- ;
        }
    }

    return min(one_flips, zero_flips) ;
}
*/