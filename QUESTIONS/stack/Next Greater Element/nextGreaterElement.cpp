#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    int n ;
    cin >> n ;
    vector <int> v(n+1) ;
    vector <int> ans(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] ;
    }
    v[n] = 0 ;
    int max = 0 ;           
    for (int i = n-1; i >= 0; i--)
    {
        if(v[i] > v[i+1] && v[i] >= max){
            ans[i] = -1 ;
            max = v[i] ;
        }
        else if(v[i] < v[i+1]){
            ans[i] = v[i+1] ;
            max = v[i+1] ;
        }
        else if(v[i] < max) ans[i] = max ;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " " << ans[i] << endl ;
    }
    
    return 0 ;
}