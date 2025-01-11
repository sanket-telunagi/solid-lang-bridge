/*
    Binary search application :

        1. lower_bound : give number if present else number greater than that
        2. upper_bound : give number greater than given number
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int lower_bound_test(int *arr, int n, int key)
{
    int lo = 0;
    int hi = n - 1;
    int mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (arr[mid] < key)
        {                 // as we are going to find element equal or greater than that
            lo = mid + 1; // right side of mid
        }
        else
        {
            hi = mid;
        }
    }
    if (arr[lo] >= key)
        return lo; // the lower element will be greater or equal to current element
    else if (arr[hi] >= key)
        return hi; // similar condition
    return -1;     // if no element found-1 -1
}

int upper_bound_test(int *arr, int n, int key)
{
    // function will return the element > key always even if element is present
    // so look for highr element
    int lo = 0;
    int hi = n - 1;
    int mid;
    while (hi - lo > 1){
        mid = (lo + hi) /2 ;
        if (arr[mid] <= key) { // go to right part without mid
            lo = mid + 1 ;    // place the lo to that point
        } else {
            hi = mid ;
        }
    }
    if (arr[lo] > key) return lo ;  // return elemnt if > key
    else if (arr[hi] > key) return hi ; 
    return -1 ; // not found 
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index = lower_bound_test(arr, n, k);
    cout << index << " " << ((index == -1) ? -1 : arr[index]) << endl;
    cout << *lower_bound(arr, arr + n, k)  << endl;

    // upper bound 
    index = upper_bound_test(arr,n,k) ;
    cout << index << " " << (index == -1 ? -1 : arr[index]) << endl ;
    cout << *(upper_bound(arr,arr+n,k)) << endl ;
    return 0;
}