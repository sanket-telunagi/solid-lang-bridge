#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {

    set<pair<int, int>> st ;
    for (auto & it : coordinates) {
        st.insert({it[0], it[1]}) ;
    }

    auto isOk = [&] (int x, int y) -> bool {
        return 0 <= x and x < m and 0 <= y and y < n ;
    } ;

    auto isThere = [&] (int x, int y ) -> bool {
        return st.find({x,y}) != st.end() ;
    };

    vector<long long> ans (5, 0) ;
    for (auto & it : st) {
        int x  = it.first , y = it.second ;

        // considering the top left 
        if (isOk(x + 1, y) and isOk(x, y + 1) and isOk(x + 1, y + 1)) {
            int res = 1 ;
            res += isThere(x +1 , y) + isThere(x , y + 1) + isThere(x + 1, y+1) ;
            ans[res] ++ ;
        }

        // considering top right block 
        if (isOk(x, y - 1) and isOk(x+ 1 , y) and isOk(x + 1 , y -1)) {
            int res = 1 ;
            res += isThere(x, y -1) + isThere(x + 1, y) + isThere(x + 1, y -1) ;
            ans [res] ++ ;
        }

        // consider as bottom left
        if (isOk(x-1, y) and isOk(x -1, y+1) and isOk(x, y+1)) {
            int res = 1 ;
            res += isThere(x -1, y) + isThere(x -1 , y + 1) + isThere (x, y + 1) ;
            ans[res]++ ;
        }

        // consider as bottom right 

        if (isOk(x - 1, y) and isOk(x , y -1) and isOk(x - 1,y - 1)) {
            int res = 1 ;
            res += isThere(x -1, y) + isThere(x, y-1) + isThere(x-1, y -1) ;
            ans[res] ++ ;
        }

    }
    
    ans [0] = (n -1) * 1LL  * (m-1) ;

    long long total = 0 ;
    for (int i = 1; i < 5; i++)
    {
        ans [i] /= i ;
        total += ans[i] ;
    }

    ans [0] -= total ;
    return ans ;
    

}

int main()
{
    int n , m , k;
    cin >> n >> m >> k ;
    vector<vector<int>> candidates(k, vector<int> (2,0)) ;

    for (int i = 0; i < k; i++)
    {
        cin >> candidates[i][0] >> candidates[i][1] ;
    }


    for (auto & it : countBlackBlocks(m, n , candidates)) cout << it << " " ;

    return 0 ;
}