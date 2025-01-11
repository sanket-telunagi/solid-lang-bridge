/*
    to solve this problem 
    just push back every bit by right shifting the number

    or just use builtin function - 

        __bulting_popcount()
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// ---- using bultin pop count function

// vector<int> countBits(int n) {
//     vector<int> pop_ct ;
//     for (int i = 0; i < n+1; i++)
//     {
//         int ct = __builtin_popcount(i) ;
//         pop_ct.push_back(ct) ;
//     }
//     return pop_ct ;
// }


// -------- using iterator

vector<int> countBits(int n) {
    vector<int> pop_ct ;
    for (int i = 0; i < n+1; i++)
    {
        int ct = 0 ;
        int temp = i ;
        while(temp) {
            if (temp & 1){
                ct++ ;
            }
            temp >>= 1 ;
        }
        pop_ct.push_back(ct) ;
    }
    return pop_ct ;
}
int main()
{
    int num ;
    cin >> num ;
    vector <int> ans = countBits(num) ;
    for (int i = 0; i < num+1; i++)
    {
        cout << ans[i] << " " ;
    }
    return 0 ;
}