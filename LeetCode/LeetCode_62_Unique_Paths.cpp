/*
    There is a robot on an m x n grid. The robot is initially located at 
    the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner 
    (i.e., grid[m - 1][n - 1]). 
    The robot can only move either down or right at any point in time.
    Given the two integers m and n, return the number of possible unique paths that the 
    robot can take to reach the bottom-right corner.

    The test cases are generated so that the answer will be less than or equal to 2 * 109.

    soln - 

        finding paths of m*n matrix has a mathematical formula as 

            -  (m + n – 2)C(n – 1) or (m + n – 2)C(m – 1)

            - (m + n – 2)! / (n – 1)! * (m – 1)! 
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
vector<vector<int>> dp(100, vector<int> (100 , -1)) ;

int uniquePaths(int m, int n) {
    if (m == 1 | n == 1) return 1 ;
    if (dp[m][n] != -1) return dp[m][n] ;
    return dp[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1) ;
}

*/

double fact(int x) {
    double ans = 1;
    if (x == 1 | x == 0) return ans ;
    for (int i = x ; i >= 2 ; i--) ans = (ans) * i ;
    return ans ;
}
int uniquePaths(int m, int n) {
    if (m == 1 | n == 1) return 1 ;
    // rounding the given ouput value
    int ans = round((fact(m + n - 2)) / (fact(n - 1) * fact(m - 1))) ;
    return ans ;
}

int main()
{
    int m, n ;
    cin >> m >> n ;
    cout << uniquePaths(m,n) <<endl ;
    return 0 ;
}