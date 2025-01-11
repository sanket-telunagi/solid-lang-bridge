#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int countDistinctWays(int n) {
    //  Write your code here.

    if (n <= 1) return 1 ;

    return countDistinctWays(n-1) + countDistinctWays(n-2)  ;
}

int main()
{

    int t ;
    cin >> t ;
    while (t--)
    {
        int num ;
        cin >> num ;
        cout << countDistinctWays(num) << endl ;
    }
    
    
    return 0 ;
}