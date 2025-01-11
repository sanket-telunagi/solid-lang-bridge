#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// bool isInteger(float n) {
//     int res = n / 1;
//     if (n > 1 && res*1 == n){
//         return true ;
//     }
//     return false ;
// }

bool isInteger(float num) {
    int temp = num ;
    float temp1 = num - temp ;
    if (temp1 > 0) {
        return false ;
    }
    return true ;
}

int main()
{
    int num ;
    cin >> num ;
    int ct = 0 ;
    for(int a = 1; a <= num ; a+=2) {
        float n1 = ( (1-a) + sqrt( (a-1)*(a-1) + (4*num) ) ) / (2);
        cout << n1 << endl ;
        if (isInteger(n1)) {
            ct++ ;
        }
    }


    cout << ct << endl ;
    return 0 ;
}