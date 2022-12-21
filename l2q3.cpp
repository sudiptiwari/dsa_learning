//Perform various operations in Double Ended Queue
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 4
template<class T>
class DoubleEndedQueue
{
private:
    T arr[SIZE];
    int front;
    int rear;
public:
    DoubleEndedQueue() : front(-1), rear(-1) {}
    bool isFrontAvailable()
    {
        if(front = 0)
            return false;
        else
            return true;
    }
    bool isRearAvailable()
    {
        if(rear == SIZE)
            return false;
        else
            return true;
    }
    // bool isFull()
    // {
    //     if(rear == SIZE)
    //         return true;
    //     else
    //         return false;
    // }
    // bool isEmpty()
    // {
    //     if((front == -1 and rear == -1) or ((front != -1 or rear != -1) and front == rear))
    //         return true;
    //     else
    //         return false;
    // }
    void addAtFront(T element)
    {
        try
        {
            if(front == -1 and rear == -1)
            {
                front = 0;
                rear = 0;
                arr[rear++] = element;
            }
            else if(isFrontAvailable())
            {
                arr[--front] = element;
            }
            else
            {
                int error;
                throw error;
            }
        }
        catch(int)
        {
            cerr<<"Front of the Deque is already full.\n";
        }
    }
    void addAtEnd(T element)
    {
        try
        {
            if(front == -1 and rear == -1)
            {
                front = 0;
                rear = 0;
                arr[rear++] = element;
            }
            else if(isRearAvailable())
            {
                arr[rear++] = element;
            }
            else
            {
                int error;
                throw error;
            }
        }
        catch(int)
        {
            cerr<<"Rear of the Deque is already full."<<endl;
        }
    }
    T deleteFromFront()
    {
        try
        {
            if(front == -1 and rear == -1)
            {
                int err;
                throw err;
            }
            else if(front != rear)
            {
                return arr[front++];
            }
            else
            {
                float error;
                throw error;
            }
        }
        catch(int)
        {
            cerr<<"Deque is empty.\n";
            return -2;
        }
        catch(float)
        {
               cerr<<"Can not delete elements from front.\n";
               return -2;
        }
    }
    T deleteFromRear()
    {
        try
        {
            if(front == -1 and rear == -1)
            {
                int err;
                throw err;
            }
            else if(/*rear != 0 and*/ front != rear)
            {
                return arr[--rear];
            }
            else
            {
                float err;
                throw err;
            }
        }
        catch(int)
        {
            cerr<<"Deque is empty.\n";
            return -3;
        }
        catch(float)
        {
            cerr<<"Can not delete elements from rear.\n";
            return -3;
        }
    }
};

int main()
{
    DoubleEndedQueue<int> q1;
    q1.addAtEnd(1);
    q1.addAtEnd(2);
    cout<<q1.deleteFromFront()<<endl;
    q1.addAtFront(11);
    cout<<q1.deleteFromRear()<<endl;
    q1.addAtEnd(22);
    cout<<q1.deleteFromRear()<<endl;
    cout<<q1.deleteFromRear()<<endl;
    return 0;
}