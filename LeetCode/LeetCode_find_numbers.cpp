#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int> find(vector<int> & nums){
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
        cin >> nums[i] ;
    }
    vector<int> ans = find(nums) ;
    cout << ans[1] << " " << ans[0] << endl ;
    return 0 ;
}