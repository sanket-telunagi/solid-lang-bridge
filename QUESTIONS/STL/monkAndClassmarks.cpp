#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

int main() {
    int t ;
    cin >> t ;
    map<int,multiset<string>> result ;
    while (t--)
    {
        int marks ;
        string names ;
        cin >> names >> marks ;
        result[-1*marks].insert(names) ;  // for setting the elements in decreasing order : negative numbers logic
    }
    // for (auto it = --result.end(); it !=result.begin() ; --it) {
    //     auto &names = (*it).second ;
    //     for(auto name : names){
    //         cout << name << " " << it->first << endl ;
    //     }
    // }
    // auto cur = --result.end() ;
    // while (true)
    // {
    