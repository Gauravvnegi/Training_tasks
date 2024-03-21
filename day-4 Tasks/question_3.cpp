// 3. Write an efficient algorithm that searches for a value in a m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

/*
 * MARK -  Program aim to Find target in a given 2D matrix
 * DESC -  serch_element(vector<vector<int>> &matrix, int target) this function checking the target by using binary serch
 * PARAM - serch_element(vector<vector<int>> &matrix, int target) taking 2D matrix and a target as an argument
 * RETURN - Returing true if the target is found else returning false
 */

#include <bits/stdc++.h>
using namespace std;
bool serch_element(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int low = 0, high = row * col - 1; // assuming the 2D matrix as a single matrix
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int minVal = matrix[mid / col][mid % col]; // dividing and taking modulo of n because we treate 2D matrix as a single array
        if (minVal == target)
        {
            return true;
        }
        else if (minVal < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}
int main()
{
    int ROW;
    int COL;
    cout << "Enter the row number : " << endl;
    cin >> ROW;
    cout << "Enter the col number : " << endl;
    cin >> COL;
    vector<vector<int>> matrix(ROW, vector<int>(COL));
    cout << "Enter the element : ";
    int count = 1;
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            cout << "Enter element : ";
            cout << endl;
            count++;
            cin >> matrix[row][col];
        }
    }
    int target;
    cout << "Enter the value of Target : ";
    cin >> target;
    bool answer = serch_element(matrix, target);
    if (answer == true) // returning true is target is found
    {
        cout << "Target Found";
    }
    else
    {
        cout << "Target Not Found"; // returning false if target not found
    };
    return 0;
}