#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

string categorizeBox(int length, int width, int height, int mass) {
    if (((length * 1LL) >= 10000 || (width * 1LL) >= 10000 || (height * 1LL) >= 10000 || (mass * 1LL) >= 10000 || (length * 1LL * width * 1LL * height) >= 1e9 ) && (mass < 100)) {
        return "Bulky" ;
    }
    if ((mass >= 100) && !((length * 1LL) >= 10000 || (width * 1LL) >= 10000 || (height * 1LL) >= 10000 || (mass * 1LL) >= 10000 || (length * 1LL * width * 1LL * height) >= 1e9 )) return "Heavy" ;
    if (((length * 1LL) >= 10000 || (width * 1LL) >= 10000 || (height * 1LL) >= 10000 || (mass * 1LL) >= 10000 || (length * 1LL * width * 1LL * height) >= 1e9 ) && (mass >= 100)) {
        return "Both" ;
    }
    else {
        return "Neither" ;
    }
}

int main()
{
    int l, w, h, m ;
    cin >> l >> w >> h >> m ;
    cout << categorizeBox(l,w,h,m) << endl ;
    return 0 ;
}