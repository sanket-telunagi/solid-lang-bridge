#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void printG(vector<vector<int>> & G) {
    int i = 0 ;
    for (auto & it : G) {
        cout << i << " : " ;
        for (auto & i : it ) {
            cout << i << " " ;
        }
        cout << endl ;
        i++ ;
    }
}

void printVV(unordered_map<int, vector<int>> & arr) {
    for (auto & pr  : arr) {
        cout << pr.first << " : " ;
        for (auto & i : pr.second) {
            cout << i << " " ;
        }
        cout << endl ;
    }
}



void DFS(int vertex , int par , int start, vector<int> & vals, vector<vector<int>> & G, vector<int> & path, map<pair<int,int>,vector<int>> & paths) {

    path.push_back(vertex) ;
    for (int child : G[vertex]) {

        if (child == par) continue ;

        if (vals[child] > vals[start]) continue ;

        // leaf node (G[child][0] == vertex)
        if ((G[child][0] == vertex) && (G[child].size() == 1)) {
            path.push_back(child) ;
            if (vals[child] == vals[start]) {
                // store unique paths
                int temp = start + child ;
                paths[{start, child}] = path ;
            }
            path.pop_back() ;
            continue ;
        }


        DFS(child, vertex, start, vals, G, path, paths) ;

    }

    path.pop_back() ;
}

int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

    // unordered_map<int,vector<int>> paths ;
    map<pair<int,int>, vector<int>> paths ;
    vector<vector<int>> G (vals.size()) ;
    vector<int> path ;

    for (int i = 0; i < edges.size(); i++)
    {
        G[edges[i][0]].push_back(edges[i][1]) ;
        G[edges[i][1]].push_back(edges[i][0]) ;
    }
 
    for (int i = 0; i < vals.size(); i++)
    {
        DFS(i, -1, i, vals, G, path, paths) ;
    }

    printG(G) ;

    int ans = vals.size() + paths.size(); 
    return ans ;
}


int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> edges;
    vector<int> vals (n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> vals[i] ;
    }
    
    for (int i = 0 ; i < n - 1 ; i++) {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        edges.push_back({v1, v2}) ;
    }

    int ans = numberOfGoodPaths(vals, edges);
    cout << ans << endl ;
    // for (auto & it : paths) {
    //     cout << it.first << " : "  ;
    //     for (auto & i : it.second) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }
    return 0 ;
}

   // printG(G) ;
    // call DFS of each node

    // DFS(2,-1,2,vals,G,path,paths) ;
    // printVV(paths) ;
    // cout << paths.size() << endl ;



// int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
//     vector<vector<int>> G (vals.size()) ;
//     for (int i = 0; i < edges.size(); i++)
//     {
//         G[edges[i][0]].push_back(edges[i][1]) ;
//         G[edges[i][1]].push_back(edges[i][0]) ;
//     }
//     vector<int> empty ;
//     // printG(G) ;
//     for (int i = 0 ; i < vals.size() ; i++) {
//         DFS(G, vals, empty, i) ;
//     }
//     int ct = 0 ; ;
//     for (auto & pr : paths) {
//         if (pr.second.size() > 1) {
//             if (vals[*pr.second.begin()] == vals[*(pr.second.end() - 1)]) {
//                 bool flag = 1; 
//                 for (int i =0 ; i < pr.second.size() ; i++) {
//                     if (vals[pr.second[i]] > vals[pr.second[0]]) {
//                         flag = 0 ;
//                     }
//                 }
//                 if (flag) {
//                     ct ++ ;
//                 }
//             }
//         }
//     }

//     int ans = vals.size() + ct ;

//     for (int i = 0; i < vals.size() - 1; i++)
//     {
//         if ((vals[i] == vals[i+1]) && (paths.find(2* i + 1) == paths.end())) {
//             ans++ ;
//         }
//     }
    

//     return ans ;
// }

// void DFS(vector<vector<int>> & G, vector<int> & vals, vector<int> & path, int vertex , int par = 0 , int sum = 0) {
//     path.push_back(vertex) ;
//     sum += vertex ;
//     for (auto & child : G[vertex]) {
//         if ((child == par) && (G[vertex].size() == 1)) {
//             paths[sum] = path ;
//             // for (auto & i : path) {
//             //     cout << i << " " ;
//             // }
//             // cout << endl ;
//             continue ;
//         }
//         if (child == par) continue;
      
//         DFS(G, vals, path, child, vertex, sum) ;
//     }
//     sum -= vertex ;
//     path.pop_back() ;
// }