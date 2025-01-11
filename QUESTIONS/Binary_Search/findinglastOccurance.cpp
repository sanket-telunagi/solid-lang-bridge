// Finding Last occurance using binary search


#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int lastOccur(vector<int> & arr, int n , int key) {
    int lo = 0 , hi = n - 1 , mid ;
    while (hi - lo > 1) {
        mid = (lo + hi) / 2 ;
        if (arr[mid] <= key) {  // go to right part of array including mid
            lo = mid ;
        }else {
            hi = mid - 1 ; // exclude mid
        }
    }
    if (arr[hi] == key) return hi ;  // highest element will be last occurance
    else if (arr[lo] == key) return lo ;
    return -1 ;
}

int main()
{
    int n ,k;
    cin >> n >> k;
    vector<int> arr(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
    }
    cout << lastOccur(arr,n,k) ;
    return 0 ;
}