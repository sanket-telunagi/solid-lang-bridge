/*
    every set with n elements has 2^n subsets 
    so we can use bit masking to generate subsets as -
    ex : 
        consider set of 2 elements = {1,2}
        possible subsets are 2^n as - 
                                    0 0 --> [] 
                                    0 1 --> [1]
                                    1 0 --> [2]
                                    1 1 --> [1,2]
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int n ;
    cin >> n ;
    int sub_ct = 1 << n ;
    vector<int> v(n) ;
    vector<vector<int>> s ;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] ;
    }
    
    for (int mask = 0; mask < sub_ct; mask++)
    {
        vector<int> sub ;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1<<i)) != 0)
            {
                sub.push_back(v[i]) ;
            }
            
        }
        s.push_back(sub) ;
        
    }
    for (auto it : s){
        for (int i : it){
            cout << i << " " ;
        }
        cout << endl ;
    }
    
    return 0 ;
}
