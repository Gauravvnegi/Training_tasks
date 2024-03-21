// 5. You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Example 2:
// Input: matrix =
// [[5,1,9,11]
// ,[2,4,8,10],
// [13,3,6,7],
// [15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000

/*
 * MARK -  Program aim to rotate the image in placedo not use extra space
 * DESC -  rotateClockWise(vector<vector<int>> &array) this function used to solve the transpose of the array and  reverse the array
 * PARAM - rotateClockWise(vector<vector<int>> &array) passing 2D array to rotate Function
 * RETURN - Returing the rotated image of the array
 */

#include <bits/stdc++.h>
using namespace std;
void rotateClockWise(vector<vector<int>> &array)
{
    int size = array.size();
    // transpose of array
    for (int row = 0; row < size; row++)
    {
        for (int col = row + 1; col < size; col++)
        {
            int temp = array[row][col];
            array[row][col] = array[col][row];
            array[col][row] = temp;
        }
    }

    // reverse each row;
    for (int row = 0; row < size; row++)
    {
        int left = 0, right = size - 1;
        while (left < right)
        {
            int temp = array[row][left];
            array[row][left] = array[row][right];
            array[row][right] = temp;
            left++;
            right--;
        }
    }
}
int main()
{
    cout << "Enter the Row number : ";
    int ROW, COL;
    cin >> ROW;
    cout << "Enter the COL number : ";
    cin >> COL;
    vector<vector<int>> array(ROW, vector<int>(COL));
    cout << "Enter the element : ";
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            cin >> array[row][col];
        }
    }
    rotateClockWise(array);
    cout << "Output : " << endl;
    for (auto row : array)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}