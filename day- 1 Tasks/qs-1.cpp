// i) Write down a method boolean isNameValid(String  name).
// A name is valid if following conditions are satisfied:
// • It does not contain any vowel more than once.
// • If the name contains two ‘S’, then there is not any ‘T’ in between them (both in capital cases).

#include <bits/stdc++.h>
using namespace std;
bool findT(string &str, int first_ind, int sec_ind) // Function to find id T is present between two S
{
    for (int ind = first_ind; ind <= sec_ind; ind++)
    {
        if (str[ind] == 'T')
        {
            return false;
        }
    }
    return true;
}
bool isNameValid(string &str)
{
    int cnt_vowel = 0;
    for (int ind = 0; ind < str.size(); ind++)
    {
        if (str[ind] == 'A' || str[ind] == 'E' || str[ind] == 'I' || str[ind] == 'O' || str[ind] == 'U')
        {
            cnt_vowel++;
        }
    }
    if (cnt_vowel > 1) // Check if there are more than 1 vowel
    {
        return false;
    }
    int find_first_S = 0, find_sec_S = 0;
    bool flag = true;
    for (int ind = 0; ind < str.size(); ind++)
    {
        if (str[ind] == 'S' && flag) // Checking The First Occurence of S
        {
            find_first_S = ind;
            flag = !flag;
        }
        if (!flag && str[ind] == 'S')
        {
            find_sec_S = ind; // Checking The Last Occurence of S
        }
    }
    return findT(str, find_first_S, find_sec_S);
}
int main()
{
    string str;
    cout << "Enter String" << endl;
    cin >> str;
    bool ans = isNameValid(str);

    if (ans == true)
    {
        cout << "Correct String";
    }
    else
    {
        cout << "Incorrect String";
    }
}