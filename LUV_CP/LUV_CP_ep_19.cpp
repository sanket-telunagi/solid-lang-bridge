#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void selection_sort(vector<int> & nums) {
    int n = nums.size() ;

    for (int i = 0; i < n; i++)
    {
        int min_index = i ;
        for (int j = i+1; j < n; j++)
        {
            if (nums[j] < nums[min_index]) {
                min_index = j ;
            }
        }
        swap(nums[i], nums[min_index]) ;
    }
    
    // time - O(n)
    // space - O(1)
}

// mereg sort 
vector<int> merger(vector<int> & nums, int l, int r, int m) {
    int l_size = m - 1 , r_size = r - m ;
    vector<int> left(l_size + 1) , right(r_size + 1) ;
    for (int i = 0; i < l_size; i++)
    {
        left[i] = nums[i + l] ;
    }
    for (int i = 0; i < r_size; i++)
    {
        right[i] = nums[i + m + 1] ;
    }
    left[l_size] = right[r_size] = INT_MAX ;
    int l_ptr = 0, r_ptr = 0 ;
    vector<int> ans(nums.size()) ;
    for (int i = l_ptr ; i <= r_ptr; i++)
    {
        if(left[l_ptr] <= right[r_ptr]) {
            ans[i] = left[l_ptr] ;
            l_ptr++ ; 
        }else {
            ans[i] = right[r_ptr] ;
            r_ptr++ ;
        }
    }
    return ans ;
}

void merge_sort(vector<int> & nums, int l, int r) {
    int m = l + (r - l) / 2 ;
    merge_sort(nums, l, m);
    merge_sort(nums, m+1, r) ;
    merger(nums, l, r, m) ;
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
    // selection_sort(nums);
    merge_sort(nums, 0, n) ;
    for(auto & i : nums) cout << i << " " ;
     return 0 ;
}