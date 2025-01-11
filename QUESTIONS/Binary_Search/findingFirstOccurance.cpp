// Finding first occurance using binary search


#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int firstOccur(vector<int> & arr, int n , int key) {
    int lo = 0 , hi = n - 1 , mid ;
    while (hi - lo > 1) {
        mid = (lo + hi) / 2 ;
        if (arr[mid] >= key) {
            hi = mid ;
        }else {
            lo = mid + 1 ;
        }
    }
    if (arr[lo] == key) return lo ;
    else if (arr[hi] == key) return hi ;
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
    cout << firstOccur(arr,n,k) ;
    return 0 ;
}