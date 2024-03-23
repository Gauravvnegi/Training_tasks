/*
Question 4:
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:
Input: height = [1,1]
Output: 1
Constraints:
n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

/*
 * MARK -   Program aim to Find the maximum Water Contain in that area
 * DESC -   Max_water_storage(vector<int> &height, int low_pointer, int high_pointer, int water_contain) - function returning the maximum area of Water Contain
 * PARAM -  Max_water_storage(vector<int> &height, int low_pointer, int high_pointer, int water_contain) - takes height ,starting position , ending position,
 *          and a maximum variable to  store maximum water Contain
 * RETURN - Returing the the maximum water capacity
 */

// Time Complexity - O(n) for finding maximum area of water storage
// Space Complexity - O(1) Constant space

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int Max_water_storage(vector<int> &height, int low_pointer, int high_pointer, int water_contain)
    {
        while (low_pointer < high_pointer) // Putting Low and High Pointer at starting position and ending position
        {
            int width = high_pointer - low_pointer; // Calculating the Width between two points
            int h = min(height[low_pointer], height[high_pointer]);
            water_contain = max(water_contain, width * h);
            if (height[low_pointer] < height[high_pointer])
                low_pointer++; // Increasing low pointer if left height is smaller
            else
                high_pointer--; // Decreasing high pointer if the height is biggerd
        }
        return water_contain;
    }

    int find_Max_area(vector<int> &height)
    {
        int low_pointer = 0;
        int high_pointer = height.size() - 1;
        return Max_water_storage(height, low_pointer, high_pointer, 0); // FInding the Max water in that area
    }
};
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution obj;
    int answer = obj.find_Max_area(height);

    cout << "The Max area is  : ";
    cout << answer;
    return 0;
}