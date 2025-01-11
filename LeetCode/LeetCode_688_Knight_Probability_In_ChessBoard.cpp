#include<bits/stdc++.h>
#include <iostream>
using namespace std ;
unordered_map<string ,double> mp ;
int moves[8][8] = {
                                {-2, -1},
                                {-1, -2},
                                {1, -2},
                                {2, -1},
                                {2, 1},
                                {1, 2},
                                {-1, 2},
                                {-2, 1}
                               } ;


double solve(int n, int k, int r , int c) {
    // knight falls off from board
    if (r < 0 || r >= n || c < 0 || c >= n) return 0 ;

    // all the moves done and knight still stays in ground
    if (k == 0) return 1.0 ;

    string key = to_string(r) + "_" + to_string(c) + "_" + to_string(k) ;

    if (mp.find(key) != mp.end()) return mp[key] ;

    double prob = 0 ;

    for (int i = 0; i < 8; i++)
    {
        cout << prob << endl ;
        prob += (solve(n, k-1, r + moves[i][0] , c + moves[i][1]) / 8.0) ;
    }

    mp[key] = prob ;
    return mp[key] ;
}
double knightProbability(int n, int k, int row, int column) {
    return solve(n, k, row, column) ;
}

int main()
{
    int n , k , r, c ;
    cin >> n >> k >> r >> c ;

    cout << fixed << setprecision(8) <<  knightProbability(n, k, r, c) ;
    return 0 ;
}