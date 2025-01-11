#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
	cin >> t ;
	while (t--) {
	    vector<int> p(4) ;
	    for (int i = 0 ; i < 4 ; i++) cin >> p[i] ;

	    if (((p[0] + p[1]) >= p[3]) || ((p[1] + p[2]) >= p[3]) || ((p[0] + p[2]) >= p[3])) cout << "YES\n" ;
	    else {
	        cout << "NO\n" ;
	    }
		
	}
    return 0 ;
}