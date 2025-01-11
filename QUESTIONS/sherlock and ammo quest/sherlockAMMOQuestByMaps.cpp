#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    map<int,multiset<string>> ammo ;
    int n ;
    cin >> n ;
    while (n--)
    {
        int a ;
        string s ;
        cin >> s >> a ;
        ammo[-1*a].insert(s) ;
    }
    for(auto it : ammo){
        for (auto name : it.second) {
            cout << name << " " << -1*it.first << endl ;
        }
    }
    return 0 ;
}