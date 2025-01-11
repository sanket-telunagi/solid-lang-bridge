#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;
        int sum = (n * (n + 1)) / 2 ;
        // sum 0f alll the elements is given by following formula
        if (sum % 2 == 0) cout << n << endl ;

        // if sum is odd we can subtract 1 to make it even hence coutn will be (n - 1)
        else cout << n -1 << endl;
        
    }
    return 0 ;
}