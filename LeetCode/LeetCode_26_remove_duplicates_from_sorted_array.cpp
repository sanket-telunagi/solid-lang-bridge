#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


void print(vector<int> nums) {
    for (auto it : nums) {
        cout << it << " " ;
    }
    cout << endl ;
}
int removeDuplicates(vector<int>& nums) {
        // int start = 0 , end = start + 1 ;
        // for (int i = 0; i < nums.size() - 1; i++)
        // {
        //     if (nums[i + 1] == nums[i]) {
        //         for (int j = i+ 1; j < nums.size(); j++)
        //         {
        //             swap(nums[j], nums[j+ 1]) ;
        //         }
        //         print(nums) ;
                
        //     }
            
        // }

    int l = 0 , r = 0 ;
    int n = nums.size() ;

    for (int r = 0; r < n; r++)
    {
        if (nums[l] != nums[r]) {
            l++ ;
            nums[l] = nums[r] ;
           
        }
        print(nums) ;
    }
    
    return l + 1 ; 
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

    cout << removeDuplicates(nums) << endl ;
    
    return 0 ;
}