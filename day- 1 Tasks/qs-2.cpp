// ii) Write a program (without using inbuilt functions and not using Strings or array) to swap first and last digits of any number
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;
    int temp = num;
    int last_num = -1;
    int first_num = -1;

    int count_digit = 0;

    last_num = num % 10; // Extracting last  number
    first_num = num;
    while (first_num >= 10) // Extracting First number
    {
        first_num /= 10;
    }

    while (temp != 0) // Counting the number of digit
    {
        temp /= 10;
        count_digit++;
    }
    int power = 1;
    for (int ind = 1; ind < count_digit; ind++)
    {
        power *= 10;
    }
    int swapp = last_num * power + num % power / 10 * 10 + first_num;
    cout << "Number Before Swap is : " << num << endl;
    cout << "Swap number is : " << swapp << endl;
    return 0;
}
