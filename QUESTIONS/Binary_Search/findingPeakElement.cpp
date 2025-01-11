/*
    Find peak element in the mountain array 
    find maximum element in the array 
    it is the monotonous array 
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int findPeak(vector<int> & arr, int n) {
    int s = 0, e = n - 1 , mid = s + (e - s) / 2 ;
    while (s < e)
    {
        if (arr[mid+1] > arr[mid]) s = mid + 1 ;
        else e = mid ;
        mid = s + (e - s) / 2 ;
    }
    return s ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for (int i = 0; i < n; i++) cin >> arr[i] ;
    cout << arr[findPeak(arr,n)] ;
    return 0 ;
}