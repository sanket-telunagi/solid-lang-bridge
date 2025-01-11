#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// int DFS(unordered_map<int, vector<int>> & graph, string & s , int & ans, int vertex = 0 , int par = -1) {
//     int ct = 0 ;
//     if ((vertex != 0 )&& (s[vertex] == s[par])) {
//         ans = 1 ;
//         return ct ;;
//     }
//     else {
//         ans++ ;
//     }

//     for(auto & child : graph[vertex]) {
//         if (child == par) continue ;
//         ct += DFS(graph, s, ans, child, vertex) + 1 ;

//     }
//     return ct ;
// }

// int longestPath(vector<int>& parent, string s) {
//     int ans = 0 ;
//     unordered_map<int, vector<int>> graph ;
//     for (int i = 0; i < parent.size(); i++)
//     {
//         if (i == 0) continue;
//         else
//         {
//             graph[parent[i]].push_back(i) ;
//             graph[i].push_back(parent[i]) ;
//         }

//     }
//     int temp = 0 ;
//     for (int i = 0 ; i < parent.size() ; i++) {
//         ans = max(ans, DFS(graph, s, temp)) ;
//         temp = 0 ;
//     }
//     return temp ;
// }

int dist[100005];
int ans = 0;
void dfs(unordered_map<int,vector<int>> & graph,string & s, int vertex = 0)
{
    dist[vertex] = 1;
    for (int child : graph[vertex])
    {
        dfs(graph, s, child);
        if (s[vertex] != s[child])
        {
            ans = max(ans, dist[vertex] + dist[child]);
            dist[vertex] = max(dist[vertex], dist[child] + 1);
        }
    }
}

int longestPath(vector<int> &parent, string s)
{
    int n = parent.size();
    unordered_map<int,vector<int>> graph ;
    for (int i = 1; i < n; i++)
    {
        graph[parent[i]].push_back(i);
    }
    dfs(graph, s);
    return ans + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
    }
    string s;
    cin >> s;

    cout << longestPath(parent, s) - 1;

    return 0;
}