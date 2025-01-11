/*
    Find minimum element using binary search
    int a monotonic array

    for a sorted array :
        first element is the lowest element and 
        last element os the greatest element
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int minElement(vector<int> & arr, int n) {
    int lo = 0 , hi = n - 1, mid , ans = INT_MAX;
    while (hi - lo > 1) {
        mid = (hi + lo) / 2;
        if (arr[mid] <= ans) {
            ans = arr[mid] ;
            hi = mid ;
        }else {
            lo = mid + 1;
        }
        if(arr[lo] <= ans) return lo ;
        else if(arr[hi] <= ans) return hi ;
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
    cout << arr[minElement(arr,n)] << endl ;
    return 0 ;
}