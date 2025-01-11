// arrange the input in decaresing order and if same ammo occures arrange names in laxographical order

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

bool comparator(pair<string,int> & a, pair<string,int> & b){
    if(a.second == b.second) return a.first < b.first ;
    return a.second > b.second ;
}

int main() {

    int n ;
    cin >> n ;
    vector<pair<string,int>> ammo(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> ammo[i].first >> ammo[i].second ;
    }
    sort(ammo.begin(),ammo.end(),comparator) ;
    for(auto it : ammo){
        cout << it.first << " " << it.second << endl ;
    }
    
    return 0 ;
}