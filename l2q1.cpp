// DSA LAB 2, Q.NO 1
// Enqueue and Dequeue in linear queue
#include <iostream>
using namespace std;
#define size 3
template <class T>
class Queue
{
private:
    T items[size];
    int front, end;

public:
    Queue() : front(0), end(0) {}
    bool isEmpty()
    {
        return (front == end);
    }
    bool isFull()
    {
        // return (end == size)
        if (end == size)
            return true;
        else
            return false;
    }
    void enqueue(T element)
    {
        if (!isFull())
            items[end++] = element;
        else
            throw(1);
    }
    T dequeue()
    {
        if (!isEmpty())
            return items[front++];
        else
            throw(1.1f);
    }
};

int main()
{
    Queue<int> q1;
    int i = 1;
    try
    {
        while (!q1.isFull())
        {
            q1.enqueue(i++); // to enter different numbers in queue
        }
    }
    catch (int)
    {
        cout << "Overflow Error." << endl;
    }
    try
    {
        while (!q1.isEmpty())
        {
            cout << q1.dequeue() << '\n';
        }
    }
    catch (float)
    {
        cout << "Underflow Error." << endl;
    }
    return 0;
}