#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void dfs(int sr, int sc, int inColor, int newColor, vector<vector<int>> & image) {

    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != inColor) return ;

    vector<pair<int,int>> movements = {
        {0,1}, {0, -1}, {1, 0}, {-1, 0}
    } ;

    if (image[sr][sc] == inColor) image[sr][sc] = newColor ;

    for(auto move : movements) {
        int nsr = sr + move.first ,
            nsc = sc + move.second ;

        dfs(nsr, nsc, inColor, newColor, image) ;
    }

}

vector<vector<int>> floodFill(vector<vector<int>> & image , int sr, int sc , int color) {
    int inColor = image[sr][sc] ;
    
    if (inColor == color) return image ;

    dfs(sr, sc, inColor, color, image) ;
    return image ;
}

int main()
{
    int m, n , sr, sc, color;
    cin >> m >> n >> sr >> sc >> color;
    vector<vector<int>> table(m, vector<int> (n, 0)) ;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j] ;
        }
        
    }

    for (auto & it : floodFill(table, sr, sc, color)) {
        for (auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    
    return 0 ;
}