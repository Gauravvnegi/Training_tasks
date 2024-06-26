// i)Write a program to remove duplicate values from an array and returns an array of unique values. int[] removeDuplicates(int[]values)
// Ex:
// values = [2, 4, 6, 2, 8, 10, 4, 12, 14, 6]
// result = [2, 4, 6, 8, 10, 12, 14]
#include <bits/stdc++.h>
using namespace std;
void removeDuplicates(vector<int> &array, vector<int> &result)
{
    unordered_set<int> seen;
    for (int value : array)
    {
        if (seen.find(value) == seen.end()) //pushing only distinct number
        {
            seen.insert(value);
            result.push_back(value);
        }
    }
}
int main()
{
    int size;
    cout << "Enter The Size of an array : " << endl;
    cin >> size;
    vector<int> array;
    for (int index = 0; index < size; index++)
    {
        int element;
        cin >> element;
        array.push_back(element);
    }
    // set<int> unique_element(array.begin(), array.end()); // Inserting element in set
    vector<int> result;
    removeDuplicates(array, result);
    cout << "Unique Element are : ";
    for (auto element : result) // Printing Unique Element
    {
        cout << element << " ";
    }
    return 0;
}
