#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    int arr[] = {1,2,3,4,6} ;
    cout << *lower_bound(arr,arr+5,45) ;
    return 0 ;
}