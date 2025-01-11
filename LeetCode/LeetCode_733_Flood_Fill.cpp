/* 
    Leetcode problem of flood fill
    733. Flood Fill
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void DFS(int i , int j ,vector<vector<int>> & image, int inColor, int newColor) {
    int n = image.size() ;
    int m = image[0].size() ;
    if (i < 0 || j < 0 || i >= n || j >= m) return ;
    if (inColor != image[i][j]) return ;

    image[i][j] = newColor ;

    // Go up 
    DFS(i, j - 1, image, inColor, newColor) ;

    // Go down 
    DFS(i, j + 1, image, inColor, newColor) ;

    // Go right
    DFS(i-1, j, image, inColor, newColor) ;

    // Go Left
    DFS(i + 1 , j, image, inColor, newColor) ;
}

vector<vector<int>> floodFill(vector<vector<int>> & image , int sr, int sc , int color) {
    int inColor = image[sr][sc] ;
    // if initial color and new color are same no need to color it again
    if(inColor != color) {
        DFS(sr,sc, image, inColor, color) ;
    }
    return image ;
}

void print(vector<vector<int>> & image) {
    for(auto it : image) {
        for (auto i : it) {
            cout << i << ' ' ;
        }
        cout << endl ;
    }
}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> image ;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp ;
        for (int j = 0; j < m; j++)
        {
            int x ;
            cin >> x ;
            temp.push_back(x) ;
        }
        image.push_back(temp) ;
    }
    int sr , sc , color;
    cin >> sr >> sc >> color;

    auto ans = floodFill(image,sr,sc,color) ;
    print(image) ;
    return 0 ;
}