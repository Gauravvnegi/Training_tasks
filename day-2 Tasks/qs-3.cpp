// iii) Write a program to print the below pattern:
// \*****/
// *\***/*
// **\*/**
// ***/***
// **/*\**
// */***\*
// /*****\


#include <bits/stdc++.h>
using namespace std;
void print_pattern(int number)
{
    cout << "Pattern is : " << endl;
    for (int row = 0; row < number; row++)
    {
        bool flag = true;

        for (int col = 0; col < number; col++)
        {
            if (row == col)
            {
                cout << "\\";
            }
            else if (row + col == number - 1)
            {
                cout << "/";
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
    }
}

int main()
{
    int number;
    cout << "Enter the number : ";
    cin >> number;
    print_pattern(number);
    return 0;
}