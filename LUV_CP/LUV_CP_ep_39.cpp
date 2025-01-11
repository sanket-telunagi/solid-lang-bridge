/*
    generate all the possible subsets :
    for an set with n elements :     
    possible subsets are : 2^n
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

vector < vector<int>> possible ;

void genSubsets(vector<int> &subsets, int i, vector<int> &num){
    if(i == num.size()){
        possible.push_back(subsets) ;
        return ;
    }

    // if element is not in subset
    genSubsets(subsets, i+1, num) ;

    // ith element in subset
    subsets.push_back(num[i]) ;
    genSubsets(subsets, i + 1, num) ;
    subsets.pop_back() ;
}

int main() {
    int n ;
    cin >> n ;
    vector <int> num(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i] ;
    }
    vector<int> empty ;
    genSubsets(empty,0,num) ;
    for(auto it : possible){
        for(auto e : it){
            cout << e << " "  ;
        }
        cout  << endl ;
    }
    
    return 0 ;
}