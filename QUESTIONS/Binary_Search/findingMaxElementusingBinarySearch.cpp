/*
    Find maximum element using binary search
    int a monotonic array
    code is partly wrong
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int maxElement(vector<int> & arr, int n) {
    int lo = 0 , hi = n - 1, mid , ans = INT_MIN;
    while (hi - lo > 1) {
        mid = (hi + lo) / 2;
        if (arr[mid] >= ans) {
            ans = arr[mid] ;
            lo = mid ;
        }else {
            hi = mid  - 1;
        }
        if(arr[hi] >= ans) return hi ;
        else if(arr[lo] >= ans) return lo ;
    }
    
}

int main()
{
    int n ;
    cin >> n ;
    vector <int> arr(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    cout << arr[maxElement(arr,n)] << endl ;
    return 0 ;
}