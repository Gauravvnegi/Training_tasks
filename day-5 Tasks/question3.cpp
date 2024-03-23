/*
Q3. You are given an array of integers array, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 Output: 3 3 4 5 5 5 6 Explanation:
Maximum of 1, 2, 3 is 3
Maximum of 2, 3, 1 is 3
Maximum of 3, 1, 4 is 4
Maximum of 1, 4, 5 is 5
Maximum of 4, 5, 2 is 5
Maximum of 5, 2, 3 is 5
Maximum of 2, 3, 6 is 6
Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4 Output: 10 10 10 15 15 90 90 Explanation:Maximum of first 4 elements is 10, similarly for next 4
elements (i.e from index 1 to 4) is 10, So the sequence
generated is 10 10 10 15 15 90 90
*/

/*
 * MARK -   Program aim to Find the maximum element in the Given K size window size
 * DESC -   find_K_max_element(vector<int> array, int window_size) This function is used find the maximum element in the Given Window
 * PARAM -  vector<int> find_K_max_element(vector<int> array, int window_size) This Function Takes array element and a given Window Size
 * RETURN - Returing the element which are greater in given window size
 */

// Time Complexity - O(n) for iterating in array for finding max element in window size
// Space Complexity - O(n) for storing max element

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(const vector<int> &nums, int k)
{
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i)
    {
        // Remove elements outside of the current window from the deque
        while (!dq.empty() && dq.front() < i - k + 1)
        {
            dq.pop_front();
        }

        // Remove elements smaller than the current element from the back of the deque
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }

        // Add current index to the deque
        dq.push_back(i);

        // If window size is reached, push  maximum element to the result
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k1 = 3;
    vector<int> result1 = maxSlidingWindow(arr1, k1);
    cout << "Output for arr1: ";
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k2 = 4;
    vector<int> result2 = maxSlidingWindow(arr2, k2);
    cout << "Output for arr2: ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
