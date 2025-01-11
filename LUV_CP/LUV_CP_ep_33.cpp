/*

    - Sorting using builtin sort algorithm
    - Called as " Introsort "
    - Introsot mixture of three sorting algorithms
        Introsort = Quick sort + Heap sort + Insertion sort
    
    Working - 
            - It starts with "Quick sort" 
                If recurssion delpth increases it switches to "Heap sort"
                    If number of elements is small it swithces to "Insertion sort"
    sort : 
        1. present in "algorithms.h" header file included in "bita/stdc++.h"
        2. sort(<start pointer>,<pointer next to ending>)
        3. Complexity - O(n) : n*log(n)
        
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    int n ; 
    cin >> n ;

    // arrays - 
    // int arr[n] ;

    // Vectors - 
    vector<int> arr(n) ;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }

    // sort(arr,arr+n) ;
    // sort(arr + 2 , arr + n) ;

    // Vectors -
    sort(arr.begin() , arr.end()) ;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }
    
    
    return 0 ;
}