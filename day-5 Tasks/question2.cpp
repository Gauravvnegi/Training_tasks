
// Q2.Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
/*
 * MARK -   Program aim to Find the median of two Sorted Array
 * DESC -   findMedian(vector<int> &nums1, vector<int> &nums2) - This function find the medain of two sorted array.
 * PARAM -  findMedian(vector<int> &nums1, vector<int> &nums2) - This Function Takes nums1 array element and nums2 array element.
 * RETURN - Returing the median of nums1 and nums2.
 */

// Time Complexity - O(log(n+m)) where m is the length of array1 and n is a length of array 2
// Space Complexity - O(m+n) size of the merge array

// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int find_median_array(vector<int> &nums1, vector<int> &nums2)
//     {
//         int size_of_nums1 = nums1.size();
//         int size_of_nums2 = nums2.size();
//         int total = size_of_nums1 + size_of_nums2;
//         int medianIndex = total / 2;

//         vector<int> merged;
//         int first_pointer = 0, second_pointer = 0;

//         while (first_pointer < size_of_nums1 && second_pointer < size_of_nums2) // Iterating to end of the array to merge  the two array in one
//         {
//             if (nums1[first_pointer] <= nums2[second_pointer])
//             {
//                 merged.push_back(nums1[first_pointer]);
//                 first_pointer++;
//             }
//             else
//             {
//                 merged.push_back(nums2[second_pointer]);
//                 second_pointer++;
//             }
//         }

//         while (first_pointer < size_of_nums1) // putting all element of array1 in merged array if they are left
//         {
//             merged.push_back(nums1[first_pointer]);
//             first_pointer++;
//         }

//         while (second_pointer < size_of_nums2) // putting all element of array2 in merged array if they are left
//         {
//             merged.push_back(nums2[second_pointer]);
//             second_pointer++;
//         }

//         if (total % 2 == 0) // if total length of merge array is even
//         {
//             return (merged[medianIndex - 1] + merged[medianIndex]) / 2;
//         }
//         else // if total length of merge array is odd
//         {
//             return merged[medianIndex];
//         }
//     }
// };
// int main()
// {
//     vector<int> nums1 = {6, 7, 8, 9, 10};
//     vector<int> nums2 = {1, 2, 3, 4, 5};
//     Solution obj;
//     cout << "Median is : " << obj.find_median_array(nums1, nums2) << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double median(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size(), n2 = b.size();
        // if n1 is bigger swap the arrays:

        int n = n1 + n2;              // total length
        int left = (n1 + n2 + 1) / 2; // length of left half

        int low = 0, high = n1; // maximum element that i can pickup
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;
            // calculate l1, l2, r1 and r2;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return (double(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            // eliminate the halves:
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};
int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {6, 7, 8, 8, 10};
    Solution obj;
    cout << "The median of two sorted array is " << obj.median(a, b) << '\n';
}
