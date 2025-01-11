#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void selection_sort(vector<int> & nums) {
    int n = nums.size() ;
    for (int i = 0; i < n-1; i++)
    {
        int min_index = i ; // current min index 
        for (int j = i + 1; j < n; j++) {
            // find for lowest number index 
            if (nums[j] < nums[min_index]) {
                min_index = j ;
            }
        }
        swap(nums[i], nums[min_index]) ;
    }
    
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    selection_sort(nums) ;
    for (auto i : nums) {
        cout << i << " " ;
    }
    cout << endl ;
    return 0 ;
}