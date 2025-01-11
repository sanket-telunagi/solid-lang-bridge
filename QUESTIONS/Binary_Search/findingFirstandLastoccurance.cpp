// Finding first and last occurance and return a pair containing indices 

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
    int n , k ;
    cin >> n >> k ;
    vector<int> arr(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    pair<int,int> occurance ;
    occurance.first = firstOccur(arr,n,k) ;
    occurance.second = lastOccur(arr,n,k) ;
    cout << occurance.first << " " << occurance.second << endl ;
    
    return 0 ;
}