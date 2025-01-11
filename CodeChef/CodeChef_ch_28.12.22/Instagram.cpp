#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while (t--) {
	    int x , y ;
	    cin >> x >> y ;
	    cout << ( x > 10*y ? "YES" : "NO" ) << endl ;
	}
	return 0;
}
