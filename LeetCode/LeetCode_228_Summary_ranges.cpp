#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<string> summaryRanges(vector<int>& nums) {
    vector<pair<int, int>> ranges;
    int r = 0 ;
    int l = 0;
    int n = nums.size() ;

    // while (r < n)
    // {
    //     while (abs(nums[i+1] - nums[i]) == 1) {
    //         r++ ;
    //         i++ ;
    //     } 
      
    //     ranges.push_back({nums[l], nums[r]}) ;
    //     l = i + 1 ;
    //     r++ ;
    //     i++ ;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     if (i+1 < n) {
    //         if (abs(nums[i+1]*1LL - nums[i]*1LL) == 1*1LL) {
    //             r++ ;
    //         } else {
    //         ranges.push_back({nums[l], nums[r]}) ;
    //         l = r+1 ;
    //         r++ ;
    //     }
    //     }
    //     else {
    //         ranges.push_back({nums[l], nums[r]}) ;
    //         l = r+1 ;
    //         r++ ;
    //     }
    // }

    // -----------
    vector<string> ans ;
    for (int i = 0; i < n; i++)
    {
        int j = i ;
        while (i+1 < n && nums[j] + 1 == nums[j+1]) {
            j++ ;
        }
        if (j > i) {
            ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j])) ;
        } else {
            ans.push_back(to_string(nums[i])) ;
        }
        
        // taking i next to j
        i = j ;
        
    }
    
    


    // for (auto & pr : ranges) {
    //     if (pr.first == pr.second) {
    //         ans.push_back(to_string(pr.first)) ;
    //     } else {
    //         ans.push_back(to_string(pr.first) + "->" + to_string(pr.second)) ;
    //     }
    // }

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

    for(string & it : summaryRanges(nums)) {
        cout << it << endl ;
    }
    
    return 0 ;
}