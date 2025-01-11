#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int n ;

    cin >> n ;

    vector<int> res ;
    unordered_map<int, vector<int>> mp , mp2;
    for (int i = 0; i < n; i++)
    {
        int x ;
        cin >> x ;
        for (int j = 0; j < x; j++)
        {
            int y ;
            cin >> y ;
            mp[i].push_back(y) ;
            mp2[y].push_back(i) ;
        }

        if (mp[i].size() == 0) res.push_back(i) ;
        
    }

    for (auto & it : mp) {
        cout << it.first << " : " ;
        for(auto i : it.second) {
            cout << i << " " ;
        }
        cout << endl ;
    }

    for (auto & it : mp2) {
        cout << it.first << " : " ;
        for(auto i : it.second) {
            cout << i << " " ;
        }
        cout << endl ;
    }

    for (auto it : res) cout << it << " " ;
    cout << endl ;

    int _size = res.size() ;

    for (int j = 0 ; j < _size ; j++) {
        int it = res[j] ;
        for(auto child : mp2[it]) {
            if (mp[child].size() == 1 && mp[child][0] == it) res.push_back(child) ;
            else if (mp[child].size() > 1) {
                for (auto i : mp[child]) {
                    if(i != child || i != it) break;
                    else {
                        res.push_back(child) ;
                    }
                }
            }
        }
    }
    sort(res.begin(), res.end()) ;
    for (auto it : res) cout << it << " " ;
    return 0 ;
}