#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// void traverse(unordered_map<int,vector<int>> & graph, string & labels,vector<int> & ans, int root = 0 , int par = 0) {
//     // ans[root] ++ ;
//     for (auto child : graph[root]) {
//         if (child == par) continue ;
//         if (labels[child] == labels[par]) {
//             ans[root]++ ;
//         }
//         traverse(graph, labels, ans, child, root) ;
//     }
// }

void DFS(unordered_map<int, vector<int>> & G, string & s, vector<int> & ans, int vertex, int parent = 0) {

    for (auto & child : G[vertex]) {

        if (child == parent) continue ;
        if (s[child] == s[vertex]) return ;
        DFS(G, s, ans, child, vertex) ;

        int temp = ans[vertex] ;
        temp = max(temp, ans[child] + 1) ;
        ans[vertex] = max(ans[vertex], temp) ;

    }

}

vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    
    vector<int> ans(n,1) ;
    unordered_map<int,vector<int>> graph ;
    for (auto & it : edges) {
        graph[it[0]].push_back(it[1]) ;
        graph[it[1]].push_back(it[0]) ;
    }
    //for (int i =0 ; i < n ; i++)
     {
    DFS(graph, labels, ans, 5) ;
    int max_distance = -1 ;
    int max_dis_node;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] > max_distance) {
            max_distance = ans[i] ;
            max_dis_node = i ;
            // cout << max << " " ;
        }
        ans[i] = 1 ;
    }
    cout << endl ;
    DFS(graph, labels, ans, max_dis_node) ;
    }
    return ans ;
}

int main()
{
    int n ;
    cin >> n ;
    // unordered_map<int,vector<int>> edges ;
    vector<vector<int>> edges(n) ;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2 ;
        cin >> v1 >> v2 ;
        // cout << v1 << " " << v2 ;
        edges[v1].push_back(v2) ;
        edges[v2].push_back(v1) ;
    }
    // for (auto & it : edges) {
    //     // cout << it.first << " : " ;
    //     for (auto i : it) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }
    string labels ;
    cin >> labels ;
    for(auto & it : countSubTrees(n,edges,labels)) {
        cout << it << " " ;
    }
    return 0 ;
}