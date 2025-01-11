#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

bool cmp(pair<int,int> &a , pair<int,int> &b){
    if(a.second == b.second) return a.first < b.first ;
    return a.second > b.second ;
}

int main() {
    string s ;
    cin >> s ;
    map<int,int> m ;
    for(char letter : s ){
        m[letter-'0'] ++ ;  // storing keys as ascii values insted of characters as maps stores in sorted order no neet to sort again
    }
    
    vector<pair<int,int>> v ; // converting a map to vector for sorting
    for(auto it : m){
        v.push_back(it) ;
    }

    sort(v.begin(),v.end(),cmp) ;
    cout << char(v[0].first + '0') ; // first element will be the answer

    return 0 ;
}