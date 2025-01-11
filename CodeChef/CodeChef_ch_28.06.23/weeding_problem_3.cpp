#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t ;
    cin >> t ;
    while (t--) {
        int n , M , K ;
        cin >> n >> M >> K ;

        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        int last = nums.back() ;

        if (last + K <= 11) {
            cout << "Yes\n" ;
        } else {
            cout << "No\n" ;
        }
        
    }
	return 0;
}
