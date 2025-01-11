#include<bits/stdc++.h>
#include <iostream>
using namespace std ;
const int M = 1e9 + 7 ;
unordered_map<string,int> mp ;


int solve1(int i , int sum , int n, vector<int> & nums) {
    if (i >= nums.size()) return 0 ;
    if (sum == n) return 1 ;

    // not take
    int ans = solve1(i+1, sum, n, nums) ;

    if (sum + nums[i] <= n) {
        ans = max(ans, solve1(i+1, sum + nums[i], n, nums) + 1) ;
    }

    return ans ;
}


int getNoOfCombinations(int num, int rem, int next, int x) {
    string key = to_string(rem) + " " + to_string(next) ;
    if (mp.find(key) != mp.end()) return mp[key] ;

    int ans = 0 ;



    if (rem == 0) ans += 1 ;

    

    int right = pow(num, (1/float(x))) ;

    for (int i = next + 1; i <= right; i++)
    {
        int temp = rem - pow(i, x) ;
        if (temp >= 0) {
            ans += getNoOfCombinations(num, temp, i, x) % M;
        }
    }
    return mp[key] = ans ;
}

int numberOfWays1(int n, int x) {

    // return getNoOfCombinations(n, n, 0, x) ;
    vector<int> nums ;
    for (int i = 0; i < n; i++)
    {
        if (pow(i, x) > n) break ;
        nums.push_back(pow(i, x)) ;
    }
    // for (auto it : nums) cout << it << " " ;
    // return solve(nums.size() -1, nums.size() -1, nums) ;
    // return 0 ;

    // int s = nums.size() ;
    // int dp[s + 1][n+1] = {0} ;
    // dp[0][0] = 1 ;
    
    // for (int i = 1; i < s; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         int no = 0 , yes = 0 ;
    //         if (j >= nums[i]) {
    //             yes = dp[i-1][j - nums[i]] ;
    //         }
    //         no = dp[i-1][j] ;
    //         dp[i][j] = (yes + no ) % M;
    //     }
        
    // }

    // for (int i = 0; i < s; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         cout << dp[i][j] << " " ;
    //     }
    //     cout << endl;
    // }
    
    
    // return dp[s - 1][n + 1] ;

    return solve1(0, 0, n, nums) ;
}
const int N = 1e9 + 7 ;

long long solve(int i, int sum , int x) {
    if (sum == 0) return 1 ;

    if (sum < 0 || pow(i, x) > sum) return 0 ;

    long long nottake = solve(i+1, sum, x) ;
    long long take = solve(i+1, sum - pow(i, x), x)  ;
    long long num = (take + nottake) % N ;
    return num ;
}

int numberOfWays(int n , int x) {
    return solve(1, n, x) ;
}

int main()
{
    int n , x ;
    cin >> n >> x ;
    cout << numberOfWays(n, x) ;
    return 0 ;
}