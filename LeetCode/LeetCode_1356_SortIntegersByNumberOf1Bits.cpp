/*
    we can use builtin popcount function with sort method
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


// ---- Doesn't work in leetcode
// bool comparator (int a , int b) {
//     if (__builtin_popcount(a) == __builtin_popcount(b) ){
//         return a > b ;
//     }
//     return __builtin_popcount(a) > __builtin_popcount(b) ;
// }

// vector<int> sortByBits(vector<int>& arr) {
//     vector<int> ans = arr ;
//     sort(ans.begin(),ans.end(),comparator) ;
//     return ans ;
// }



int pop_ct(int n){
    int ct = 0 ;
    while(n) {
        if (n & 1) {
            ct++ ;
        }
        ct >>= 1 ;
    }
    return ct ;
}

bool comparator (int a , int b) {
    int pop_ct_a = pop_ct(a), pop_ct_b = (pop_ct(b)) ;
    
    if (pop_ct_a == pop_ct_b ){
        return a > b ;
    }
    return pop_ct_a > pop_ct_b ;
}


vector<int> sortByBits(vector<int> & arr){
    vector<int> ans = arr ;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            if(comparator(ans[i],ans[j])) {
                swap(ans[i],ans[j]) ;
            }
        }
        
    }
    return ans ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> v(n) , ans;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] ;
    }

    ans = sortByBits(v) ;
    for (int i : ans) {
        cout << i << ' ' ;
    }
    
    return 0 ;
}