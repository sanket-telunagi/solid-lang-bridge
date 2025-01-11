#include <iostream>
#include <vector>
#include<bits/stdc++.h>
// Helper function to check if a given position is within the grid and is not an obstacle
bool is_valid(const std::vector<std::vector<int>>& grid, int x, int y) {
  return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != -1;
}

// DFS function to explore all possible paths from the starting square to the ending square
// void dfs(const std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, int x, int y, int& count) {
//   // Mark the current square as visited
//   visited[x][y] = true;

//   // Check if we have reached the ending square
//   if (grid[x][y] == 2) {
//     // Check if we have visited all non-obstacle squares
//     bool all_visited = true;
//     for (int i = 0; i < grid.size(); i++) {
//       for (int j = 0; j < grid[0].size(); j++) {
//         if (grid[i][j] != -1 && !visited[i][j]) {
//           all_visited = false;
//           break;
//         }
//       }
//       if (!all_visited) break;
//     }
//     if (all_visited) {
//       // Increment the counter for valid paths
//       count++;
//     }
//     return;
//   }

//   // Try moving to the adjacent squares
//   if (is_valid(grid, x - 1, y)) dfs(grid, visited, x - 1, y, count);
//   if (is_valid(grid, x + 1, y)) dfs(grid, visited, x + 1, y, count);
//   if (is_valid(grid, x, y - 1)) dfs(grid, visited, x, y - 1, count);
//   if (is_valid(grid, x, y + 1)) dfs(grid, visited, x, y + 1, count);

//   // Mark the current square as not visited
//   visited[x][y] = false;
// }



// DFS function to explore all possible paths from the starting square to the ending square
// int dfs(const std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, int x, int y, const std::pair<int, int>& end) {
//   // Mark the current square as visited
//   visited[x][y] = true;

//   // Check if we have reached the ending square
//   if (std::make_pair(x, y) == end) {
//     // Check if we have visited all non-obstacle squares
//     bool all_visited = true;
//     for (int i = 0; i < grid.size(); i++) {
//       for (int j = 0; j < grid[0].size(); j++) {
//         if (grid[i][j] != -1 && !visited[i][j]) {
//           all_visited = false;
//           break;
//         }
//       }
//       if (!all_visited) break;
//     }
//     if (all_visited) {
//       // Return 1 for a valid path
//       return 1;
//     } else {
//       // Return 0 for an invalid path
//       return 0;
//     }
//   }

//   // Helper function to check if a given position is within the grid and is not an obstacle
//   auto is_valid = [&](int x, int y) {
//     return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != -1 && !visited[x][y];
//   };

//   // Try moving to the adjacent squares
//   int count = 0;
//   if (is_valid(x - 1, y)) count += dfs(grid, visited, x - 1, y, end);
//   if (is_valid(x + 1, y)) count += dfs(grid, visited, x + 1, y, end);
//   if (is_valid(x, y - 1)) count += dfs(grid, visited, x, y - 1, end);
//   if (is_valid(x, y + 1)) count += dfs(grid, visited, x, y + 1, end);

//   // Mark the current square as not visited
//   visited[x][y] = false;

//   return count;
// }

int dfs(const std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, int x, int y, const std::pair<int, int>& end) {
  // Check if we have visited all non-obstacle squares
  bool all_visited = true;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] != -1 && !visited[i][j]) {
        all_visited = false;
        break;
      }
    }
    if (!all_visited) break;
  }

  // Return 0 if we have not visited all non-obstacle squares or if we have reached a dead end
  if (!all_visited || grid[x][y] == -1) return 0;

  // Return 1 if we have reached the ending square and visited all non-obstacle squares
  if (std::make_pair(x, y) == end) return 1;

  // Mark the current square as visited
  visited[x][y] = true;

  // Helper function to check if a given position is within the grid and is not an obstacle
  auto is_valid = [&](int x, int y) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != -1 && !visited[x][y];
  };

  // Try moving to the adjacent squares
  int count = 0;
  if (is_valid(x - 1, y)) count += dfs(grid, visited, x - 1, y, end);
  if (is_valid(x + 1, y)) count += dfs(grid, visited, x + 1, y, end);
  if (is_valid(x, y - 1)) count += dfs(grid, visited, x, y - 1, end);
  if (is_valid(x, y + 1)) count += dfs(grid, visited, x, y + 1, end);

  // Mark the current square as not visited
  visited[x][y] = false;

  return count;
}


int main() {
  // Initialize the grid
  std::vector<std::vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,2}} ;

  // Initialize the visited matrix
  std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));

  // Find the starting square
  int start_x, start_y;
   std ::  pair <int,int> end ;
  for (int i = 0; i < grid.size() ; i++){
    for (int j = 0; j < grid.size(); j++)
    {
        if (grid[i][j] == 1) {
            start_x = i ;
            start_y = j ;
        }
        if (grid[i][j] == 2) {
            end.first = i;
            end.second = j ;
        }
    }
    
  }

  int count = 0;
  count = dfs(grid,visited,start_x, start_y,end) ;
  std :: cout << count << std :: endl ;

  return 0 ;

}
