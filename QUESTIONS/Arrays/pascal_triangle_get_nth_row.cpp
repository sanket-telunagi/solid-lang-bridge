#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> getNthRow(int n) {
    vector<int> row  ;
    // insert first element manually
    long long res = 1 ;


    // nth row has n elements 
    row.push_back(res) ;


    for (int c = 1; c < n; c++)
    {
        // it works similar to n-1Cr
        res = res * (n - c) ;
        res = res / c ;
        row.push_back(res) ;
    }
    return row ;
}

int main()
{
    int n ;
    cin >> n ;
    for (auto it : getNthRow(n)) {
        cout << it << " " ;
    }
    cout << endl ;
    return 0 ;
}