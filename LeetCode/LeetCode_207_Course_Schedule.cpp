#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<bool>  vis, inStk ;
unordered_map<int, vector<int>> mp ;

// bool isLoopExist (int ver, int par) {
//     bool isLoop = false ;

//     vis[ver] = true ;

//     for (auto child : mp[ver]) {

//         // if its the same node
//         if (child == par && vis[child]) continue;

//         if (vis[child]) return true ;

//         isLoop |= isLoopExist(child, ver) ;
//     }

//     return isLoop ;
// }

bool isLoopExist (int ver) {
    if (inStk[ver]) return true ;

    if (vis[ver]) return false ;

    vis[ver] = true ;
    inStk[ver] = true ;

    for (auto child : mp[ver]) {
        if (isLoopExist(child)) return true ;
    }

    inStk[ver] = false ;

    return false ;
}

void print(unordered_map<int,vector<int>> & graph) {
    for(auto & pr : graph) {
        std :: cout << pr.first << " : "  ;
        for (auto & it : pr.second) {
            std :: cout << it << " " ;
        }
        std :: cout << endl ;
    }
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vis.resize(numCourses, 0) ;
    inStk.resize(numCourses, 0) ;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        mp[prerequisites[i][1]].push_back(prerequisites[i][0]) ;
    }
    print(mp) ;
    for (int i = 0; i < numCourses; i++)
    {
        if (mp.find(i) == mp.end()) continue;
        if (isLoopExist(i)) return false ;
    }
    
    return true ;
}

int main()
{
    int numCourses , nEdges;
    cin >> numCourses >> nEdges;

    vector<vector<int>> vec ;
    for (int i = 0; i < nEdges; i++)
    {
        int x , y ;
        cin >> x >> y ;
        vec.push_back({x,y}) ;
    }
    
    cout << canFinish(numCourses, vec) << endl ;

    return 0 ;
}