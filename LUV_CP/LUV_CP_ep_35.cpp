#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    // Lower bounds and Upper Bounds 

    /*
        Lower Bound - returns a location of element if the element is present else location of greater element than that
        Upper Bound - returns a location of element greater than the element even if the same number is present

        Both reutns a pointer in case of array and iterator in case of vectors or maps
    */

    int a[] = {2,2,3,4,5,6} ;
    int n = 6 ;
    cout << *lower_bound(a, a+6, 5) << " " << *upper_bound(a,a+6,4) << endl ;
    return 0 ;
}