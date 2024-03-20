// v) Write a program to find the smallest number divisible by all the numbers between 1 to n.
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
} // find least common multiple

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
int check_smallest_num(int digit)
{
    int res = 1;
    for (int num = 2; num <= digit; num++)
    {
        res = lcm(res, num);
    }
    return res;
}
int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;
    if (num < 1)
    {
        cout << "Enter Number Greater than 1 " << endl;
    }
    else
    {
        int ans = check_smallest_num(num);
        cout << "The smallest number divisible by all the numbers between 1 to n : " << ans;
    }
}