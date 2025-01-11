#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int mx_subset_sum(vector<int> rods) {
    int n = rods.size() ;

    int sum = accumulate(rods.begin(), rods.end(), 0) ;

    int table[n+1][sum + 1] ;

    for (int i = 0; i <= n; i++)
    {
        table[i][0] = true ;
    }
    for (int i = 1; i <= sum; i++)
    {
        table[0][i] = false ;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (rods[i-1] <= j) {
                
                table[i][j] = table[i-1][j] + table[i-1][j - rods[i - 1]] ;
            } else {
                table[i][j] = table[i-1][j] ;
            }

            // std :: cout << table[i][j] << " " ;
        }
        // std :: cout << endl ;
    }

    vector<int> possibles ;
    for (int i = 0; i <= sum; i++)
    {
        if (table[n][i] > 1)  {
            possibles.push_back(table[n][i]) ;
        }
    }
    int res = INT_MIN ;
    for (auto it : possibles) {
        res = max(res, (sum - 2 * it)) ;
    }
    
    return res ;
    
}

bool isPos(int index, int sum, int dp [][1010], vector<int> & rods) {
    if (sum == 0) return true ;
    if (index < 0) return false ;

    if (dp[index][sum] != -1) return dp[index][sum] ;
    // not chosen 
    bool res = isPos(index - 1, sum , dp, rods) ;

    if (rods[index] <= sum)
    res |= isPos(index - 1, sum - rods[index], dp, rods) ;

    return dp[index][sum] = res ;
}

int tallestBillboard(vector<int>& rods) {
    int dp[30][1010] ;
    int n = rods.size() ;
    memset(dp, -1, sizeof(dp)) ;

    int sum = accumulate(rods.begin(), rods.end(), 0) ;
    // if (sum % 2 != 0) return 0 ;

    // range 0 -> sum
    int res = 0 ;
    for (int s = sum / 2 ; s >= 0; s--) {
        int req = s / 2 ;
        if (isPos(n-1, req, dp, rods) == 1) {
            res = max(res, s) ;
            // cout << s << " " ;
        }
    }

    return res ;
}

int main()
{
    int n ;
    std :: cin >> n ;
    vector<int> rods(n) ;
    for (int i = 0; i < n; i++)
    {
        std :: cin >> rods[i] ;
    }
    
    // cout << mx_subset_sum(rods) << endl ;
    std :: cout << tallestBillboard(rods) << endl ;
    return 0 ;
}