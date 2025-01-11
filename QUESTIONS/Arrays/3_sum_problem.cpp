#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*

    return all the triplets from the array which adds up to zero 
*/


vector<vector<int>> Three_sum_by_pointers (vector<int> & nums) {
    vector<vector<int>> res ;
    int n = nums.size() ;

    // sort the array 
    sort(nums.begin(), nums.end()) ;

    // apply
    for (int i = 0; i < n ; i++)
    {
        if (i != 0 && nums[i] == nums[i-1]) continue; 

        int left = i + 1 ,
            right = n - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right] ;
            if (sum > 0) right -- ;
            else if (sum < 0) left ++ ;
            else {
                vector<int> temp = {
                    nums[i],
                    nums[left],
                    nums[right]
                } ;

                // sort(temp.begin(), temp.end()) ;

                res.push_back(temp) ;

                left ++ ;
                right -- ;

                while (left < right && nums[left] == nums[left - 1]) left++ ;
                while (left < right && nums[right] == nums[right + 1]) right-- ;  
            }
        }
    }
    return res ;
}

vector<vector<int>> Three_Sum_by_set(vector<int> & nums) {
    set<vector<int>> st ; // store elements in sorted order and avoid duplicate triplets 
    int n = nums.size() ;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> mp ;

        for (int j = i+1; j < n; j++)
        {
            int target = -1 *(nums[i] + nums[j]) ;
            if(mp.find(target) != mp.end()) {
                vector<int> temp = {
                    nums[i], 
                    nums[j], 
                    target
                };

                sort(temp.begin(), temp.end()) ;

                st.insert(temp) ;
            }
            // mp.insert(nums[j]) ;
            mp.insert(nums[j]) ;
        }
        

    }

    vector<vector<int>> res(st.begin(), st.end()) ;

    return res ;
    
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

    // for (auto it : Three_Sum_by_set(nums)) {
    //     cout << it[0] << " " << it[1] << " " << it[2] << "\n" ;
    // }
    for (auto it : Three_sum_by_pointers(nums)) cout << it[0] << " " << it[1] << " " << it[2] << endl ;
    return 0 ;
}