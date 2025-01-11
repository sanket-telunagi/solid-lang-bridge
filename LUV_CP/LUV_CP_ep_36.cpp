/*
    STL Algorithms - 

        1. min_element( start, end) - returns a pointer or iterator
        2. accumulate( start, end , initial sum) - returns sum of array elements + initial sum
        3. count ( start, end , element) - returns count of specified element in the array
        4. Find (start, end , element) - retruns pointer to element if element is present or the last pointer if not present
        5. Reverse ( start , end ) - reverses array even works for strings

    complexity - O(n)
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    int a [] = {2,2,3,4,5,6} ;
    reverse(a , a+ 6) ;
    for (int e : a) {
        cout << e << " " ;
    }

    cout << *min_element(a,a+6) << " " << *(max_element(a,a+6)) << " " << count(a, a+6, 2) ;
    return 0 ;
}