#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
	cin >> t ;
	while(t--) {
	    int n ;
	    cin >> n ;
	    int ct = n ;
	    vector<int> a(n), b(n) ;
	    for (int i = 0 ; i < n ; i++) {
	        cin >> a[i] ;
	    }
        for (int i = 0 ; i < n ; i++) {
	        cin >> b[i] ;
	    }
        for (int i = 0 ; i < n ; i++) {
            if((a[i] > (2 * b[i])) || (b[i] > (2 * a[i]))) ct-- ;
        }
	    cout << ct  << endl ;
	}
    return 0 ;
}