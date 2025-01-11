#include <iostream>
using namespace std;

int ct(string & s) {
    int c = 0 ;
    for (char & ch : s) if (ch == '1') c++ ;
    return c ;
}

void ct(string & s, string & x, int n) {
    for (int i = 0; i < n - 1; i++) 
        x.push_back(((s[i] - '0') ^ (x[i] - '0')) + '0') ;
}
int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--) {
	    int n ;
	    cin >> n ;
	    string s , x ;
	    cin >> s ;
	    
        // x[0] = 1
        x.push_back('1') ;
        ct(s,x,n) ;
        // for (int i = 0; i < n - 1; i++) 
        //     x.push_back(((s[i] - '0') ^ (x[i] - '0')) + '0') ;

        int l1 = ct(x) ;

        // x[0] = 0
        x = "" ;
        x.push_back('0') ;
        
        ct(s,x,n) ;
        // for (int i = 0; i < n - 1; i++) 
        //     x.push_back(((s[i] - '0') ^ (x[i] - '0')) + '0') ;

        int l0 = ct(x) ;
        int res = max(l0, l1) ;
        
        cout << res << endl ;
	}
	return 0;
}