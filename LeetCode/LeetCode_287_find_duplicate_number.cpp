#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// -------- try to find by bit manipulation
int findDuplicate(vector<int> & nums){
    int ans ;
    for(int i = 0 ; i < nums.size() - 1 ; i++){
        int temp = nums[i]^nums[i+1] ;
        if(temp == 0){
            ans = nums[i] ;
        }
    }
    return ans ;
}



// int findDuplicate(vector<int>& nums) {
//     unordered_map<int,int> mp ;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         mp[nums[i]]++ ;
//     }
//     for(auto & pr : mp){
//         if(pr.second > 2) { // there could be all elements same
//             return pr.first ;
//         }
//     }
     
// }



int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << findDuplicate(nums) ;
    return 0 ;
}