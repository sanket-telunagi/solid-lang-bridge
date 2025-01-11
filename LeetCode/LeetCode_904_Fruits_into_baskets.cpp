#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void printV(vector<bool> & ans) {
    for (auto i : ans) cout << i << " " ;
    cout << endl ;
}

void printV(vector<int> & ans) {
    for (int & i : ans) cout << i << " " ;
    cout << endl ;
}


int helper(vector <int> & fruits, int index) {
    int n = fruits.size() ;
    vector <bool> b1 (n) , b2(n);
    int b1_type = 2 , b2_type = 2;
    for (int i = index; i < n; i++)
    {
        // no fruits
        if (fruits[i] == 0) break;

        if ((b1_type  == 0)) break;

        if (!b1[fruits[i]]) {
            b1[fruits[i]] = 1 ;
            b1_type-- ;
            continue;
        } 
        if (!b2[fruits[i]]) {
            b2[fruits[i]] = 1;
           
            continue;
        }
        // if (b1[fruits[i]] & b2[fruits[i]]) break;
    }
    cout << "b1 " << "(" << index << ") : "  ;
    printV(b1) ;
    cout << endl ;
    cout << "b2 " << "(" << index << ") : "  ;
    printV(b2) ;
    cout << endl ;
  
    int ct = 0 ;
    for (int i = 0; i < n; i++)
    {
        if (b1[i]) ct++ ;
        if (b2[i]) ct++ ;
    }
    return ct ;
}

int totalFruit(vector<int>& fruits) {
    int n = fruits.size() ;
    // vector<int> hsh(n) ;
    // for (int i = 0; i < n; i++)
    // {
    //     hsh[i] = helper(fruits, i) ;
    // }
    // int ans = INT_MIN ;
    // for (int i = 0; i < n; i++)
    // {
    //     ans = max(ans, hsh[i]) ;
    // }
    // // printV(hsh) ;
    // return ans ;

    int l = 0 , total = 0 , res = 0 ;
    unordered_map<int, int> ct ;
    for (int i = 0; i < n; i++)
    {
        ct[fruits[i]] ++ ;
        total ++ ;

        while (ct.size() > 2) {
            int f = fruits[l] ;
            ct[f] -- ;
            total-- ;
            l++;
            if(ct[f] == 0) {
                ct.erase(f) ;
            }
        }

        res = max(res, total);
    }
    return res ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> fruits(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i] ;
    }
    cout << totalFruit(fruits) << endl ;
    return 0 ;
}