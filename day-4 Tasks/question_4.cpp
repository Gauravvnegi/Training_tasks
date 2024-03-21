// 4. Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are surrounded by water.
// Input: grid = [
//   ['1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]

/*
 * MARK -  Program aim to Find the number of land in a grid
 * DESC -   bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid) this function
 *          checking if the adjacent element is land or not
 *          Find_Land(vector<vector<char>> &grid) this function count the number of land in a grid by calling BFS
 * PARAM - bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid) this function consist of row number , col number
 *          ,Visited array and a grid
 *          Find_Land(vector<vector<char>> &grid) this function take grid as an argument
 * RETURN - Returing the total number of land the grid have
 */
#include <bits/stdc++.h>
using namespace std;
void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
{
    queue<pair<int, int>> qu; // Pushing row value and column in queue;
    visited[row][col] = 1;
    qu.push({row, col});
    int ROW = grid.size();
    int COL = grid[0].size();
    int delrow[] = {-1, 0, 1, -1}; // Direction of row where it can move
    int delcol[] = {0, 1, 0, -1};  // Direction of col where it can move
    // Iterating Until the Queue is not empty
    while (!qu.empty())
    {
        int row = qu.front().first;
        int col = qu.front().second;
        qu.pop();

        for (int ind = 0; ind < 4; ind++) // Moving to all four Direction
        {
            int newRow = delrow[ind] + row;
            int newCol = delcol[ind] + col;
            if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL)
            {
                if (grid[newRow][newCol] == '1' && !visited[newRow][newCol])
                {

                    visited[newRow][newCol] = 1;
                    qu.push({newRow, newCol});
                }
            }
        }
    }
}
int Find_Land(vector<vector<char>> &grid)
{
    int ROW = grid.size();
    int COL = grid[0].size();
    vector<vector<int>> visited(ROW, vector<int>(COL, 0));
    int count_land = 0;
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            if (!visited[row][col] && grid[row][col] == '1') // Calling bfs only when we are at land
            {
                count_land++; // Counting the number of land
                bfs(row, col, visited, grid);
            }
        }
    }
    return count_land;
}
int main()
{
    cout << "The land and water matrix are : ";
    vector<vector<char>> grid{
        {'1', '0', '0', '1', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '0'},
        {'0', '0', '0', '1', '0'}};

    int total_land = Find_Land(grid);
    cout << "Total Land are : " << total_land;
    return 0;
}