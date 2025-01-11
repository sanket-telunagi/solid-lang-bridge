#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// vector<int> singleNumber(vector<int>& nums) {
//     map<int,int> mp ;
//     vector<int> ans ;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         mp[nums[i]]++ ;
//     }
//     for(auto & pr : mp) {
//         if (pr.second == 1) {
//             ans.push_back(pr.first) ;
//         }
//     }
   
//     return ans ;
// }

vector<int> singleNumber(vector<int> & nums){
    vector<int> ans ;
    int a = 0 ;
    int temp = 0 ;
    sort(nums.begin(),nums.end()) ;
    for (int i = 0; i < nums.size(); i++)
    {
        temp = temp ^nums[i] ;
    }
    for (int i = 0; i < nums.size()-1; i++)
    {
        a = temp^nums[i] ;
        if (a == nums[i+1] ) {
            ans.push_back(nums[i+1]) ;
        }
    }
    ans.push_back(temp ^ ans[0]) ;
    return ans ; 
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ; ;
    }
    for( auto i : singleNumber(nums)) {
        cout << i << " " ;
    }
    return 0 ;
}