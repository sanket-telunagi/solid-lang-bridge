#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

 void solve(int idx, vector<int> & nums, vector<vector<int>> & ans) {
    if (idx == nums.size()){ 
        ans.push_back(nums);
        return ;
    }
    for (int i = idx; i < nums.size(); i++)
    {
       
        swap(nums[i], nums[idx]) ;
        solve(idx + 1, nums, ans) ;
        swap(nums[i], nums[idx]) ;
    }

    
    
}


bool isEqual(vector<int> & nums1 , vector<int> & nums2) {
    int n = nums1.size() ;

    for (int i = 0 ; i < n ; i ++) {
        if (nums1[i] != nums2[i]) return false ;
    }
    return true ;
}
    void nextPermutation1(vector<int>& nums) {
        // bool set = false ;

        // int n = nums.size() ;

        // for (int i = n -1 ; i > 0 ; i--) {
        //     for (int j = i -1 ; j > 0 ; j--) {

        //         if (nums[i] > nums[j]) {
        //             swap(nums[i], nums[j]) ;
        //             set = true ;
        //             break ;
        //         }
        //     }
        //     if (set) break ;
        // }

        // if (!set) {
        //     reverse(nums.begin(), nums.end()) ;
        // }
        vector<vector<int>> res ;
        solve(0, nums, res ) ;

        int idx = 0 ;
        sort(res.begin(), res.end()) ;

        for (int i = 0 ; i < res.size(); i++) {
            if (isEqual(res[i], nums)) {
                idx = i % res.size() + 1 ;
                break ;
            }

            // for (int it : res[i]) {
            //     cout << it << " " ;
            // }
            // cout << endl ;
        }

        // for (auto & it : res) {
        //     for (auto i : it) {
        //         cout << i << " " ;
        //     }
        //     cout << endl ;
        // }
        // cout << idx << endl ;
        nums = res[idx] ;

    }

    void nextPermutation(vector<int> & nums) {

        /*
        
            Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
            For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
            To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
            If such a break-point does not exist i.e. if the array is sorted in decreasing order, 
            the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
            So, in this case, we will reverse the whole array and will return it as our answer.
            If a break-point exists:
            Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
            Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.
        */

        int bPoint = -1 ;

        int n = nums.size() ;
        for (int i = n -1 ; i > 0; i--)
        {
            /* code */

            if (nums[i] > nums[i-1]) {
                // idx = i ;
                // get the bPoint by substracting the index according to this algo 
                bPoint = i - 1;
                break ;
            }
        }

        if (bPoint == -1) {
            reverse(nums.begin(), nums.end()) ;
        }
        
        else {
            for (int i = n -1 ; i > bPoint; i--) {
                if (nums[i] > nums[bPoint]) {
                    swap(nums[i], nums[bPoint]) ;
                    break ;
                }
            }
            reverse(nums.begin() + bPoint + 1, nums.end()) ;

        }

    }

int main()
{
    int  n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> nums[i] ;
    }

    nextPermutation(nums) ;

    // vector<vector<int>> ans ;
    // solve(0, nums, ans) ;

    // for (auto it : ans) {
    //     for (auto i : it) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }

    for (int i : nums) cout << i << " " ;
    cout << endl ;
    
    return 0 ;
}