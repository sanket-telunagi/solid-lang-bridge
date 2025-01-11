#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int bfs(vector<pair<int,int>> * tree, vector<int> & level, int n, int m) {

    deque<int> dq ;
    dq.push_back(1) ;
    level[1] = 0 ;

    while (!dq.empty())
    {
        int cur_node = dq.front() ;
        dq.pop_front() ;

        for(auto & pr : tree[cur_node]) {
            int node = pr.first ;
            int wt = pr.second ;

            if(level[cur_node] + wt < level[node]) {
                level[node] = level[cur_node] + wt ;
                if(wt == 1) {
                    dq.push_back(node) ;
                }else {
                    dq.push_front(node) ;
                }
            }
        }
    }
    return level[n] ;

}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<pair<int,int>> tree [n+1] ;
    for (int i = 0; i < m; i++)
    {
        int x , y ;
        cin >> x >> y ;
        // converting to 0 wt and 1 wt
        if(x == y) continue;
        // wt 0
        tree[x].push_back({y,0}) ;
        // wt 1
        tree[y].push_back({x,1}) ;
    }

    vector<int> level(n+1, -1) ;

    cout << bfs(tree, level, n , m) ;
    
    return 0 ;
}