/*
    Binary search :

        applicable for any monotonic function 
        monotonic : either increasing , decresing, x^2, X^n
        or array like : T T T T F F F F
        or color boxes : B B B B W W W W
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

int BinarySearch(int *arr,int n, int key) {
    int lo = 0 ; // start position
    int hi =  n - 1; // last position
    int mid ;
    while (hi - lo > 1) { // never runs in a infinite loop
        mid = (lo + hi) / 2 ;
        if (arr[mid] < key) {
            lo = mid + 1 ;
        }else {
            hi = mid ;  // mid and end
        }
    }
    // now we have lo and hi pointers or two points to check and return index
    if(arr[lo] == key) return lo ;
    else if (arr[hi] == key) return hi ;
    return -1 ; // not found 
}

int main() {
    int n ,k;
    cin >> n >> k;
    int arr[n] ;
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
    }
    int index = BinarySearch(arr,n,k) ;
    cout << index << " " << ( index == -1 ? -1 : arr[index]) << endl;
    return 0 ;
}