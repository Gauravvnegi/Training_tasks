// 2. Write a program to print all the possible combinations according to the input values.
// Example :
// Given Values
// '1' : ['Z', 'Y', 'A'],
// '2' : ['B', 'O'],
// '12' : ['L']
// '3' : ['U', 'P']
// Input: 123
// Output : [ZBU, ZBP, ZOU, ZOP, YBU, YBP, YOU, YOP, ABU, ABP, AOU, AOP, LU, LP]

/*
 * MARK -  Program aim to Find all possible combination according to input
 * DESC -  generateCombinations(map<string, vector<string>> &values, string input, string current, int index) this function find all possible combinations
 * PARAM -  generateCombinations(map<string, vector<string>> &values, string input, string current, int index) take a
 *          inputed map , string ,empty string , and a starting index
 * RETURN - Returing All the combinations
 */
#include <bits/stdc++.h>
using namespace std;

void generateCombinations(map<string, vector<string>> &values, string input, string current, int index)
{
    if (index == input.size())
    {
        cout << current << " "; // returning the combination
        return;
    }

    string digit = input.substr(index, 1);
    if (values.find(digit) != values.end())
    {
        for (string s : values[digit])
        {
            generateCombinations(values, input, current + s, index + 1);
        }
    }
    if (index + 1 < input.size()) // check wheather there is at least one more character after current
    {
        string combined_digit = input.substr(index, 2);
        if (values.find(combined_digit) != values.end())
        {
            for (string s : values[combined_digit])
            {
                generateCombinations(values, input, current + s, index + 2); // Checking for combination of digit
            }
        }
    }
}

int main()
{
    map<string, vector<string>> values = {
        {"1", {"Z", "Y", "A"}},
        {"2", {"B", "O"}},
        {"12", {"L"}},
        {"3", {"U", "P"}}};
    string input = "123";
    string current = "";
    cout << "ALL the combination are : ";
    generateCombinations(values, input, current, 0);

    return 0;
}