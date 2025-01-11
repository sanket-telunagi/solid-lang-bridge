#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

class shodh_jodi {

    public :

        vector<int> p , s;

        shodh_jodi(int vertex) {
            for (int i = 0 ; i < vertex; i++) {
                p.push_back(i) ;
                s.push_back(1) ;
            }
            
        }

        int shodh (int x) {
            if (p[x] != x) p[x] = shodh(p[x]) ;
            return p[x] ;
        }

        int jodi (int x, int y) {
            int xr = shodh(x), yr = shodh(y) ;

            if (s[xr] < s[yr]) swap(xr, yr) ;
            p[yr] = xr ;
            s[xr] += s[yr] ;
        }
};


class Solution {
    public : 

        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
            
            sort(edgeList.begin(), edgeList.end()) ;

            vector<vector<int>> q ;

            for (int i = 0; i < queries.size() ; i++) {
                vector<int> temp ;
                temp.push_back(i) ;
                for (int v : queries[i]) {
                    temp.push_back(v) ;
                }
                q.push_back(temp) ;
            }

            shodh_jodi ds = shodh_jodi(n) ;

            vector<bool> ans (false, q.size()) ;

            int ind = 0 ;
            for (auto & que : q) {
                int i = que[0], 
                    pi = que[1],
                    qi = que[2],
                    lim = que[3] ;

                while (ind < edgeList.size()){
                    int u = edgeList[ind][0] ,
                        v = edgeList[ind][1] ,
                        dis = edgeList[ind][2] ;

                    if (dis >= lim) break;
                    ds.jodi(u,v) ;
                    ind += 1 ;
                }

                ans[i] = (ds.shodh(pi), ds.shodh(qi)) ;
                
            }

            return ans ;

        }
};

int main()
{
    
    return 0 ;
}