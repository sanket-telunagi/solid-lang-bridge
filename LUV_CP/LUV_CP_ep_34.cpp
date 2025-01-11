// Comaprator functions in sorting algorithms

/*
    Every sorting algorithms contains a condition for comparision
    comarision function returns "bool" value to swap
    it works in reverse condition that if it is "false" it swaps

    to use it return whatever condition you want
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

// sosrting in increasing order
bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first != b.first) {
        return a.first < b.first ;
    }
    return a.second < b.second ;
}

int main() {
    int n ;
    cin >> n ;
    vector<pair<int,int>> v(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second  ;
    }
    sort(v.begin(),v.end() , cmp) ;
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl ;
    }
    
    return 0 ;
}