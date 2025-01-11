/*
    Breadth First Search - 

        - Traverse the breadth first 
        - Used to find shortest path
        - A visited array is used to keep track of visited array
        - A "queue" data structure is used to visit the nodes 

*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void BFS(vector<vector<int>> & graph , vector<bool> & visited, vector<int> & level, vector<int> & order) {
    // queue of node
    queue<int> q ;
    q.push(0) ; // push root


    // rul loop till the queue becomes empty
    while (!q.empty())
    {
        // take first node into consideration
        int curr_node = q.front() ;

        // pop it from queue
        q.pop() ;

        // pushing into the order 
        order.push_back(curr_node) ;

        // mark the node visited 
        visited[curr_node] = true ;

        // its children are the the next level
        for(int & child : graph[curr_node]) {

            // if child is not visited visit it
            if(!visited[child]) {

                // push child into queue
                q.push(child) ;

                // add the level of the child
                level[child] = level[curr_node] + 1 ;
            }
        }
    } 
}

int main()
{
    // nodes
    int n ;
    cin >> n ;

    // graph 
    vector<vector<int>> graph(n+1) ;
    for (int i = 0; i < n - 1; i++)
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        graph[v1].push_back(v2) ;
        graph[v2].push_back(v1) ;
    }
    

    // nodes start from 1
    vector<bool> visited(n+1) ;

    // Level of each node
    vector<int> level(n+1) ;

    // Visiting order
    vector<int> order;

    // do the BFS
    BFS(graph, visited, level, order) ;

    // printing the order 
    for(auto i : order) cout << i << " " ;

    cout << endl ;

    // print the level
    int i = 0 ;
    for(auto l : level) cout << i++ << " : " <<  l << endl ;

    return 0 ;
}