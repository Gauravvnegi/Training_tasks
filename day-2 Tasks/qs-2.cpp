// ii) Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum.
// The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets.
// The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending
// order with respect to the numbers they hold. If no three numbers sum up to the target sum, the function should return an empty array.
// Ex:
// target_sum = 6
// nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
// result = [[1, 2, 3]]
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> find_triplet(vector<int> &array, int size, int target)
{
    sort(array.begin(), array.end());
    vector<vector<int>> result;
    for (int itr = 0; itr < size; itr++)
    {
        if (itr != 0 || array[itr] == array[itr - 1]) // skipping if current and previous element is same
            continue;
        int low_pointer = itr + 1;   // puting low_pointer one step ahead from previous pointer
        int high_pointer = size - 1; // putting last pointer at last element position3
        while (low_pointer < high_pointer)
        {
            int sum_of_triplet = array[low_pointer] + array[high_pointer] + array[itr];
            if (sum_of_triplet < target) // Increasing low_pointer pointer if sum_of_triplet is smaller than the target
            {
                low_pointer++;
            }
            else if (sum_of_triplet > target) // Decresing high_pointer if the sum_of_triplet is greater than the taget
            {
                high_pointer--;
            }
            else
            {
                if (sum_of_triplet == target)
                {
                    vector<int> temp = {array[itr], array[low_pointer], array[high_pointer]};
                    result.push_back(temp); // Pushing the triplet in  result array
                }

                low_pointer++;
                high_pointer--;
                while (low_pointer < high_pointer && array[low_pointer] == array[low_pointer - 1])
                {
                    low_pointer++; // Skipping the case if current low pointer is equals to previous low pointer
                }
                while (low_pointer < high_pointer && array[high_pointer] == array[high_pointer + 1])
                {
                    high_pointer--; // Skipping the case if current high pointer is equals to previous high pointer
                }
            }
        }
    }
    return result;
}
int main()
{
    int size;
    cout << "Enter the size of an array : " << endl;
    cin >> size;
    vector<int> array;
    for (int ind = 0; ind < size; ind++)
    {
        int ele;
        cin >> ele;
        array.push_back(ele);
    }
    int target;
    cout << "Enter the value of Target : " << endl;
    cin >> target;

    vector<vector<int>> result = find_triplet(array, size, target);
    for (auto element : result)
    {
        for (auto itr : element)
        {
            cout << itr << " ";
        }
        cout << endl;
    }
    return 0;
}
