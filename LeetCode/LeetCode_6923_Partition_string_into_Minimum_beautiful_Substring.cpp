#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPowerFive(long long num) {
    if (num < 125) return num == 1 || num == 5 || num == 25 ;

    if (num % 125 != 0) return false ;

    else return isPowerFive(num / 125) ;
}

long long getNumber (string & s, int l, int r) {
    long long ans = 0 ;

    for (int i = l; i < r; i++)
    {
        ans = ans * 2 + (s[i] - '0') ;
    }
    return ans ;
    
}

int minimumBeautifulSubstrings(string s) {
    int n = s.length() ;
    int dp[n + 1];
 

    memset(dp, n + 1, sizeof(dp));
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
 
        if (s[i - 1] == '0')
            continue;
        for (int j = 0; j < i; j++) {
 
            if (s[j] == '0')
                continue;
 
            long long num = getNumber(s, j, i);
 
            // Check for power of 5
            if (!isPowerFive(num))
                continue;
 
            // Assigning min value to get min cut possible
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
 
    // (n + 1) to check if all the strings are traversed
    // and no divisible by 5 is obtained like 000000
    return ((dp[n] < n + 1) ? dp[n] : -1);
}

int main()
{
    string s ;
    cin >>s ;
    cout << minimumBeautifulSubstrings(s) ;
    return 0 ;
}