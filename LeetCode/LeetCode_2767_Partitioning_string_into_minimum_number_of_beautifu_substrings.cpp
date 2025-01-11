#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isPow_5(string s , int i , int j) {
    int num = 0 ;
    int p = 0 ;
    for (int k = i; k >= j ; k--)
    {
        num += (s[k] - '0') * pow(2, p++) ;
    }
    // cout << num << endl ;
    return num == 1 || num % 5 == 0 ;
}

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
    return isPowerFive(ans) ;
    
}

int solve (string & s, int i) {
    if (!(s[i] - '0')) {
        return 16 ;
    }
    if (i == s.length()) return 0 ;
    int n = s.length() ;

    int res = INT_MAX ;
    for (int k = i; k < n; k++)
    {
        if (getNumber(s, k , i)) {
            res = min(res, 1 + solve(s, k + 1)) ;
        } 
    }
    return res ;
}


int minimumBeautifulSubstrings(string & s) {
    int ans = -1 ;
    return solve(s, 0) == 16 ? -1 : solve(s,0) ;
}

int main()
{
    string s ;
    cin >>s ;

    cout << minimumBeautifulSubstrings(s) << endl ;
    return 0 ;
}