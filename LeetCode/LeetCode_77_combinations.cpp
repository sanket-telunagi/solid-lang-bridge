#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given two integers n and k, return all possible combinations of 
    k numbers chosen from the range [1, n].

    You may return the answer in any order.
*/

void genCombinations(vector<int> & arr, vector<int> & empty, vector<vector<int>> & ans, int & k, int index = 0) {
    if (index >= arr.size()) {
        if (empty.size() == k) {
            ans.push_back(empty) ;
        }
        return ;
    }
    // current index not taken
    genCombinations(arr, empty, ans, k ,index + 1) ;

    // current index taken
    empty.push_back(arr[index]) ;
    genCombinations(arr, empty, ans, k , index + 1) ;
    empty.pop_back() ;
    
}

vector<vector<int>> combine(int n, int k) {
    vector<int> arr, empty ;
    vector<vector<int>> ans ;
    for (int i = 1; i <= n; i++) arr.push_back(i) ;
    genCombinations(arr, empty, ans, k) ;
    return ans ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<vector<int>> ans = combine(n,k);
    for (auto it : ans)
    {
        for (int i : it ){
            cout << i << " " ;
        }
        cout << endl ;
    }
    
    return 0 ;
}