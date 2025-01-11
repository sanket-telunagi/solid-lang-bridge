#include <iostream>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t ;
	while (t--){int n, x, k , p ;
	cin >> n >> x >> k >> p ;
	
	if (k == n) p += 20 ;
	while (k--) {
	    if (x > 0) {
	        p += 10 ;
	        x-- ;
	    } else {
	        p += 5 ;
	    }
	}
	
	cout << p << endl ;}
	return 0;
}
