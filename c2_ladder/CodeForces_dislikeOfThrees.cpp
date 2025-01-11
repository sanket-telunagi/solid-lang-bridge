#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    O(n) - 
        use while loop iterate till count equals k cout last number
*/

int main()
{
    int n ;
    cin >> n ;
    vector<int> v ;
    while(n--) {
        int x ;
        cin >> x ;
        v.push_back(x) ;
    }
    vector<int> series ;
    int max_ele = *max_element(v.begin(),v.end()) ;
    int ct = 0,i= 1 ;
    while(ct != max_ele) {
        if(!((i % 3 == 0 ) | (i % 10 == 3))) {
            series.push_back(i) ;
            ct++ ;
        }
        i++ ;
    }
    for(int i = 0 ; i < v.size() ; i++) {
        cout << series[v[i]-1] << endl ;
    }
    return 0 ;
}