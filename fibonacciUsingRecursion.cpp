#include <iostream>
using namespace std;
int fibonacciTail(int n, int a = 0, int b = 1)
{
    if (n == 1)
        return a;
    else if (n == 2)
        return b;
    else
        return fibonacciTail(n - 1, b, a + b);
}
int fibonacciNonTail(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return (fibonacciNonTail(n - 1) + fibonacciNonTail(n - 2));
}
int main()
{
    int n;
    cout << "Enter the term: ";
    cin >> n;
    cout << "The required fibonacci term(non tail) is:" << fibonacciNonTail(n) << endl;
    cout << "The required fibonacci term(tail) is:" << fibonacciTail(n) << endl;
    return 0;
}