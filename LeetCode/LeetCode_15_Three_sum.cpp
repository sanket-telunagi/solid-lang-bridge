/*
    Given an integer array nums, 
    return all the triplets [nums[i], nums[j], nums[k]] 
    such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    Notice that the solution set must not contain duplicate triplets
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int binSearch(vector<int> & nums, int s, int target) {
    int e = nums.size() - 1 ;
    while (e - s > 1)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] < target) {
            s = mid + 1 ;
        }else {
            e = mid;
        }
    }
    return nums[e] == target ? e : -1 ;
}

vector<vector<int>> threeSum2(vector<int>& nums) {
    sort(nums.begin(),nums.end()) ;
    vector<vector<int>> trips;
    set<vector<int>> buffer ;
    int p1 = 0 , p2, p3 ;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        p1 = i ;
        for (int j = p1 + 1; j < nums.size() - 1; j++)
        {  
            p2 = j ;
            int target = -1 * (nums[p1] + nums[p2]) ;
            int ans = binSearch(nums, p2, target) ;
            if (ans != -1) {
                buffer.insert({nums[p1],nums[p2],nums[ans]}) ;
            }
            else {
                break ;
            }
        }
    }
    for (auto & it : buffer) {
        trips.push_back({it[0], it[1], it[2]}) ;
    }
    buffer.clear() ;
    return trips ;   
}

vector<vector<int>> threeSum(vector<int> & nums) {

    // vector<vector<int>> res ;

    // unordered_map<int, int> mp ;

  
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         int target = -(nums[i] + nums[j]) ;
    //         if (mp.find(target) != mp.end()) {
    //             if (target + nums[i] + nums[j] == 0 && i != j && j != mp[target] && i != mp[target])
    //             res.push_back({nums[i], nums[j], target}) ;
    //         }
    //         mp[target] = j ;
    //     }
        
    // }
    


    // return res ;

    int n= nums.size();
        sort(nums.begin(),nums.end());
        if(n<3 || nums[0]>0)return {};
        
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[nums[i]]=i;
        
        vector<vector<int>>ans;
        
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i]==nums[i-1])continue;
            if(nums[i]>0)break;
            
            for(int j=i+1;j<n-1;j++){
                
                if(j!=i+1 && nums[j]==nums[j-1])continue;
                int twosum = -(nums[i]+nums[j]);
                
                if(mp.find(twosum)!=mp.end())
                    if(mp[twosum]>j)
                        ans.push_back({nums[i],nums[j],twosum});
            }
        }
        return ans;
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

    for (auto it : threeSum(nums)) {
        cout << it [0] << " " << it [1] << " " << it[2] << endl ;
    };
    
    return 0 ;
}