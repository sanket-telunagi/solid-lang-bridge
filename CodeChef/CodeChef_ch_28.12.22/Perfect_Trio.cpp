#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--) {
	    int a, b , c ;
	    cin >> a >> b >> c ;
	    cout << (( a == b + c || b == a + c || c == a + b) == 1 ? "YES" : "NO") << endl ; 
	}
	return 0;
}
