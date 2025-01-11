#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


vector<int> findArray(vector<int>& pref) {
    vector <int> v ;
    v.push_back(pref[0]) ;
    for (int i = 1; i < pref.size(); i++)
    {
        v.push_back(pref[i]^pref[i-1]) ;
    }
    return v ;
    }


int main()
{
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] ;
    }
    for(int i : findArray(v)){
        cout << i << " " ;
    }
    return 0 ;
}