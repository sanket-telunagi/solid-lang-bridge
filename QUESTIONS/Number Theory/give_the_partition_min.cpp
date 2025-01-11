/*
    Given an integer 'N' return the partion 
    so that the difference is minimum 

    Eg : 
        N = 4
        ans = 2 2

        N = 5
        ans = 3 2

*/

#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while(t--) {
        long long n ;
        cin >> n ;
        double temp = n / 2.0 ;
        cout << ceil(temp) << " " << floor(temp) << endl ;
    }
    return 0 ;
}
