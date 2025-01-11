#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t ;
	while (t--) {
	    int x ;
	    cin >> x ;
	    cout << (x % 3 == 0 ? "YES\n" : "NO\n") ;
	}
	return 0;
}