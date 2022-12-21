// DSA LAB 2, Q.NO 2
// Enqueue and Dequeue in circular queue
#include<iostream>
using namespace std;
#define SIZE 4
template<class T>
class CircularQueue
{
private:
    T arr[SIZE];
    int front;
    int rear;
public:
    CircularQueue () : front(-1), rear(-1) {}
    bool isFull()
    {
        if(front == (rear) % SIZE)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if(front == -1 and rear == -1)
            return true;
        else
            return false;
    }
    void EnQueue(T element)
    {
        try
        {
            if(front == -1 and rear == -1)
            {
                front =0;
                rear =0;
                arr[rear++] = element;
            }
            else if(front > -1 and rear > -1 and !isFull())
            {
                arr[(rear++) % SIZE] = element;
            }
            else if(isFull())
            {
                int error;
                throw (error);
            }
        }
        catch(int)
        {
            cerr<<"Queue is full.\n";
        }
    }
    T DeQueue()
    {
        try
        {
            if(!isEmpty() and front != rear)
            {
                return arr[(front++) % SIZE];
            }
            else if(!isEmpty() and front == rear)
            {
                T temp = front;
                front = -1;
                rear = -1;
                return arr[temp];
            }
            else if(isEmpty())
            {
                float err;
                throw (err);
            }
        }
        catch(float)
        {
            cerr<<"Queue is empty.\n";
            return -1;
        }
    } 
};

int main()
{
    CircularQueue<int> c1;
    c1.EnQueue(1);
    c1.EnQueue(2);
    c1.EnQueue(3);
    c1.EnQueue(4);
    cout<<"Dequeuing one element: "<<c1.DeQueue()<<endl;
    c1.EnQueue(11);
    c1.EnQueue(22); 
    cout<<"Dequeuing process..."<<endl;
    cout<<c1.DeQueue()<<endl;
    cout<<c1.DeQueue()<<endl;
    cout<<c1.DeQueue()<<endl;
    cout<<c1.DeQueue()<<endl;
    return 0;
}