#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

long long minDist(long long a, long long b, long long c) {
    return abs(a-b) + abs(a-c) + abs(b-c) ;
}

int main()
{
    long long t ;
    cin >>t ;
    while (t--) {
        long long a, b, c ;
        cin >>a >> b >> c ;
        long long res = min({
            minDist(a+1, b, c),
            minDist(a, b+1, c),
            minDist(a, b, c+1),
            minDist(a+1, b+1, c),
            minDist(a+1, b, c+1),
            minDist(a, b+1, c+1),

            minDist(a+1, b+1, c+1),

            minDist(a-1, b, c),
            minDist(a, b-1, c),
            minDist(a, b, c-1),
            minDist(a-1, b-1, c),
            minDist(a-1, b, c-1),
            minDist(a, b-1, c-1),

            minDist(a-1, b-1, c-1)

        }) ;
        cout <<  (res == 0 ? 0 : res - 2) << endl ;    
     }
    return 0 ;
}