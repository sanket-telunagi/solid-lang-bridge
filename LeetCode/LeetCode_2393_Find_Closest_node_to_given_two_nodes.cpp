#include<bits/stdc++.h>
#include <iostream>
using namespace std ;



void traverse(vector<int> & g, vector<int> & dis, int node, int d, vector<int> & ves) {
    
    if (node != -1 && !ves[node]) {
        ves[node] = 1 ;
        dis[node] = d    ;
        traverse(g, dis, g[node], d + 1, ves);
    }
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    unordered_map<int, vector<int>> graph;
  

    vector<int> dis_n1(edges.size(), INT_MAX), dis_n2(edges.size(), INT_MAX), vis(edges.size(),0) ;
    traverse(edges, dis_n1, node1,0, vis) ;
    vis.assign(edges.size(), 0);
    traverse(edges, dis_n2, node2,0, vis) ;
    
    int min_dist = INT_MAX;
    int dis = -1 ;
    for (int i = 0; i < edges.size(); i++)
    {
        if (dis_n1[i] == -1 || dis_n2[i] == -1) continue;
        if (min_dist > max(dis_n1[i], dis_n2[i])) {
            min_dist = max(dis_n1[i], dis_n2[i]) ;
            dis = i ;
        }
    }
    
    return dis ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> edges(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i] ;
    }
    int n1, n2 ;
    cin >> n1 >> n2 ;
    cout << closestMeetingNode(edges, n1, n2) << endl ;
    return 0 ;
}