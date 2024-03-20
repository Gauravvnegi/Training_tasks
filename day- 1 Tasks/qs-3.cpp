// iii) Find the largest number less than N whose each digit is prime number
#include <bits/stdc++.h>
using namespace std;
bool check_prime(int n) // Checking number is Prime or Not
{
    if (n <= 1)
        return false;
    for (int digit = 2; digit * digit <= n; digit++)
    {
        if (n % digit == 0)
            return false; // Returning false if number is Non prime
    }
    return true;
}

int prime_digit(int num) // Finding the Number less than num
{
    while (num > 0)
    {
        int temp = num;
        bool flag = true;
        while (temp > 0)
        {
            int digit = temp % 10;
            if (!check_prime(digit))
            {
                flag = false;
                break;
            }
            temp /= 10;
        }
        if (flag)
            return num;
        num--;
    }
    return -1;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int answer = prime_digit(num);
    if (answer != -1)
    {
        cout << "Largest prime digit number is " << num << " : " << answer << endl;
    }
    else
    {
        cout << "No number found." << endl;
    }
    return 0;
}
