/*
    Problem : 
        You are climbing a staircase. It takes n steps to reach the top
        Each time you can either can climb '1' or '2' steps. In how many distinct ways you can climb to the top .
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<vector<int>> paths ;
int cnt = 0 ;
void gen(vector<int> &path, int n) {
    if (n < 0 || cnt == n) {
        paths.push_back(path) ;
        return ;
    }

    // taken step 1 
    path.push_back(1) ;
    cnt++ ;
    gen(path,n-1) ;
    

    // taken step 2
    path.push_back(2) ;
    cnt++ ;
    gen(path,n-2) ;
    
}

int main() {
    int n ;
    cin >> n ;
    vector<int> empty ;
    gen(empty,n) ;
    // cout << paths.size() << endl ;

    // for(auto it : paths){
    //     for(auto e : it){
    //         cout << e << " " ;
    //     }
    //     cout << endl ;
    // }

    cout << cnt << endl ;

    return 0 ;
}