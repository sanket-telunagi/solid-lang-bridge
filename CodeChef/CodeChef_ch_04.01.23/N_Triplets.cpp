#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// void generate(vector<int> & nums, vector<int> & empty , vector<vector<int>> & ans,int n , int index = 0) {
//     if (index >= nums.size()) {
//         if (empty.size() == 3 && ((empty[0]*1LL*empty[1]) <= n) && ((empty[0]*1LL*empty[2]) <= n) && ((empty[2]*1LL*empty[1]) <= n)) {
//             if (((n*1LL) % (empty[0]*1LL*empty[1]) == 0) && ((n*1LL) % (empty[0]*1LL*empty[2]) == 0) && ((n*1LL) % (empty[1]*1LL*empty[2]) == 0)) {
//                 if (max((empty[0]*1LL*empty[1]*1LL*empty[2]), (n*1LL)) % min((empty[0]*1LL*empty[1]*1LL*empty[2]), (n*1LL)) == 0) {
//                     ans.push_back(empty) ;
//                     index = nums.size() ;
//                     return ;
//                 }
//             }
//         }
//         return ;
//     }

//     // Number not taken
//     generate(nums, empty, ans,n , index + 1) ;

//     // number taken
//     empty.push_back(nums[index]) ;
//     generate(nums, empty, ans,n , index + 1) ;
//     empty.pop_back() ;
// }

// vector<vector<int>> genCombination(vector<int> & nums, int n) {
//     vector<vector<int>> pos_nums ;
//     vector<int> empty ;
//     generate(nums, empty, pos_nums, n) ;
//     return pos_nums ;
// }

// vector<int> possible(vector<vector<int>> & pos_nums, int n) {
//     for (auto & it : pos_nums) {
//         if (max((it[0]*1LL*it[1]*1LL*it[2]), (n*1LL)) % min((it[0]*1LL*it[1]*1LL*it[2]), (n*1LL)) == 0) {
//             if (((it[0]*1LL*it[1]) <= (n*1LL)) && ((it[1]*1LL*it[2]) <= (n*1LL)) && ((it[0]*1LL*it[2]) <= (n*1LL))) {
//                 if (((n*1LL) % (it[0]*1LL*it[1]) == 0) && ((n*1LL) % (it[0]*1LL*it[2]) == 0) && ((n*1LL) % (it[1]*1LL*it[2]) == 0)) {
//                     return it ;
//                 }
//             }
//         }
//     }
//     vector<int> ans(1,0) ;
//     return ans;
// }

void print(vector<int> & nums) {
    for (auto i : nums) {
        cout << i << " " ;
    }
    cout << endl ;
}

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;

        vector<int> primt_factors ;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                if(j == n)
                    primt_factors.push_back(i) ;
            }
            
        }

        print(primt_factors) ;
        for (int i = primt_factors.size() - 1; i > 0 ; i--)
        {
            if(primt_factors[i] * 1LL * primt_factors[i-1] > n) {
                primt_factors.pop_back() ;
            }
        }
        print(primt_factors) ;
        // vector<vector<int>> pos_nums = genCombination(primt_factors, n) ;

        // vector<int> ans = possible(pos_nums, n) ;
        // if (ans.size() == 1) {
        //     cout << -1 << endl ;
        // }else {
        //     for (int i = 0; i < 3; i++)
        //     {
        //         cout << ans[i] << " " ;
        //     }
        //     cout << endl ;
        // }
        
        // for (auto & it : pos_nums) {
        //     for (auto & i : it) {
        //         cout << i << " " ;
        //     }
        //     cout << endl ;
        // }
        
    
  
        
    }
    
    return 0 ;
}