/*

Q1 Find all interleavings of given strings that can be formed from all the characters of the first and second string where the order of characters is preserved.

Input: str1 = "AB",  str2 = "CD"
Output:
    ABCD
    ACBD
    ACDB
    CABD
    CADB
    CDAB
Input: str1 = "AB",  str2 = "C"
Output:
    ABC
    ACB
    CAB
*/

/*
 * MARK -   Program aim to Find the maximum element in the Given K size window size
 * DESC -   find_K_max_element(vector<int> array, int window_size) This function is used find the maximum element in the Given Window
 * PARAM -  vector<int> find_K_max_element(vector<int> array, int window_size) This Function Takes array element and a given Window Size
 * RETURN - Returning the element which are grater in given window size.
 */

// Time Complexity -pow(2,n+m)
// Auxilary stack space = O(n+m)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void interleavedStrings(string str1, string str2, string result)
    {
        if (str1.empty() && str2.empty()) // Printing the Combination if Both the string are empty
        {
            cout << result << endl;
            return; // backtracking the choices
        }
        if (!str1.empty())
        {
            interleavedStrings(str1.substr(1), str2, result + str1[0]); // Recursion Call Until string one become empty
        }
        if (!str2.empty())
        {
            interleavedStrings(str1, str2.substr(1), result + str2[0]); //// Recursion Call Until string second become empty
        }
    }
};
int main()
{
    string str1 = "AB";
    string str2 = "C";
    Solution obj;
    obj.interleavedStrings(str1, str2, ""); // Function to find interleving string
    return 0;
}
