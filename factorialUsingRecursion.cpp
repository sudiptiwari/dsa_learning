#include <iostream>
using namespace std;
int FactorialNonTailRecursion(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * FactorialNonTailRecursion(n - 1));
}

int FactorialTailRecursion(int n, int result = 1)
{
    if (n == 0)
        return result;
    else
        return FactorialTailRecursion(n - 1, result * n);
}
int main()
{
    int n;
    cout << "Enter any non negative number: ";
    cin >> n;
    cout << "By Head recursion, n! = " << FactorialNonTailRecursion(n) << endl;
    cout << "By Tail recursion, n! = " << FactorialTailRecursion(n) << endl;
    return 0;
}