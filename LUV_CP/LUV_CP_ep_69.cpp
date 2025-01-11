/*
    Representation of Graphs

        1. Adjecency Matrix Representaion
        2. Adjecency List Representaion
    
    These both store and represent edges 


    input - 

        n : no. of vertices 
        m : edges 
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

const int N = 1e3 + 10 ;

/*
    matrix :
        1. space complexity n^2
        2. cant create matrix > 10^4
        3. finding connection is O(n)
*/
int graph_metrix [N+1][N+1] ;

/*
    List :
        1. space complexity (V+E)
            V : Vertices
            E : Edges
*/
vector<int> graph_list [N+1] ;  // Array of vectors

void print_graph() {
    for (int i = 1; i <= 6; i++)
    {
        for(int it : graph_list[i]){
            cout << it << ' ' ;
        }
        cout << endl ;
    }
}

int main()
{
    int n, m ;
    cin >> n >> m ;
    while(m--) {
        int v1, v2 ;
        cin >> v1 >> v2 ;
        graph_metrix[v1][v2] = 1 ;
        graph_metrix[v2][v1] = 1 ;

        /* Representation using Lists */
        graph_list[v1].push_back(v2) ;
        graph_list[v2].push_back(v1) ;
        print_graph() ;
        
    }
    cout << "Matrix Representaion --- " << endl ;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cout << graph_metrix[i][j] << " " ;
        }
        cout << endl ;
    }

    cout <<"\nList Representation ---- " << endl ;
    for (int i = 1; i <= 6; i++)
    {
        for(int it : graph_list[i]){
            cout << it << ' ' ;
        }
        cout << endl ;
    }
    
    return 0 ;
}