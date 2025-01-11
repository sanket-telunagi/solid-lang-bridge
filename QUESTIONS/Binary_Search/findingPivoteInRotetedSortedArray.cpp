/*
    Pivote is minimum element in the array
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

int givePivote(vector<int> & arr) {
    int lo = 0 , hi = arr.size() - 1 , mid ;
    while (hi - lo > 1) {
        mid = lo + (hi - lo) / 2 ;
        if(arr[mid] >= arr[0]) {
            lo = mid + 1 ; // on first line move forward without mid
        } else {
            hi = mid ; // on second line with mid
        }
    }
    return lo <= hi ? lo : hi ;
}

int main() {
    
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for (int i =0 ; i < n ; i++) {
        cin >> arr[i] ;
    }

    cout << givePivote(arr) << endl;

    return 0 ;
}