#include <iostream>
using namespace std;
class DLinkedList
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node *previous;
        Node(int element = 0)
        {
            data = element;
            next = NULL;
            previous = NULL;
        }
    };
    Node *start;

public:
    DLinkedList()
    {
        start = NULL;
    }
    void DisplayDLinkedList()
    {
        Node *pointer = start;
        cout << "\n";
        while (pointer != NULL)
        {
            cout << pointer->data << "<-->";
            pointer = pointer->next;
        }
    }
    void InsertAtBeginning(int element)
    {
        if (start == NULL)
        {
            Node *n = new Node;
            n->data = element;
            n->next = NULL;
            n->previous = NULL;
            start = n;
            n = NULL; delete n;
        }
        else
        {
            Node *n = new Node;
            n->data = element;
            n->next = start;
            n->previous = NULL;
            start->previous = n;
            start = n;
            n = NULL; delete n;
        }
        DisplayDLinkedList();
    }
    void InsertAtEnd(int element)
    {
        if (start == NULL)
        {
            InsertAtBeginning(element);
        }
        else
        {
            Node *temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *n = new Node;
            n->data = element;
            n->next = NULL;
            n->previous = temp;
            temp->next = n;
        }
        DisplayDLinkedList();
    }
    void InsertAfterNode(int value, int element)
    {
        Node *temp = start;
        while (temp->data != value)
        {
            temp = temp->next;
        }
        Node *n = new Node;
        n->data = element;
        n->next = temp->next;
        n->previous = temp;
        temp->next = n;
        temp->next->previous = n;
        temp = NULL;
        delete temp;
        n = NULL;
        delete n;
        DisplayDLinkedList();
    }
    void InsertBeforeNode(int value, int element)
    {
        Node *temp = start;
        while (temp->next->data != value)
        {
            temp = temp->next;
        }
        Node *n = new Node;
        n->data = element;
        n->next = temp->next;
        n->previous = temp;
        temp->next = n;
        temp->next->previous = n;
        DisplayDLinkedList();
    }
    void DeleteFromBeginning()
    {
        if (start == NULL)
        {
            cout << "Underflow error!";
        }
        else
        {
            start = start->next;
            start->previous = NULL;
        }
        DisplayDLinkedList();
    }
    void DeleteFromEnd()
    {
        if (start == NULL)
        {
            cout << "Underflow error!";
        }
        else
        {
            Node *temp = start;
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next->previous = NULL;
            temp->next = NULL;
            DisplayDLinkedList();
        }
        DisplayDLinkedList();
    }
    void DeleteAfterNode(int value)
    {
        Node *temp = start;
        while (temp->data != value)
        {
            temp = temp->next;
        }
        Node *pointer = temp->next;
        temp->next = pointer->next;
        pointer->next->previous = temp;
        // delete temp; *throws segmentation error*
        temp = NULL;
        delete temp;
        delete pointer;
        DisplayDLinkedList();
    }
    void DeleteBeforeNode(int value)
    {
        if (start->data == value)
        {
            cout << "Underflow error." << endl;
        }
        else if(start->next->data == value)
        {
            DeleteFromBeginning();
        }
        else
        {
            Node *temp = start;
            while (temp->next->next->data != value)
            {
                temp = temp->next;
            }
            Node* postptr = temp->next->next;
            temp->next = postptr;
            postptr->previous = temp;
            delete temp;
            delete postptr;
            DisplayDLinkedList();
        }
    }
};

int main()
{
    DLinkedList d1;
    d1.InsertAtBeginning(2);
    d1.InsertAtBeginning(1);
    d1.InsertAtEnd(3);
    d1.InsertAfterNode(2, 33);
    d1.InsertBeforeNode(33, 22);
    d1.DeleteFromBeginning();
    d1.DeleteFromEnd();
    d1.DeleteAfterNode(2);
    //d1.InsertBeforeNode(33,12);
    //d1.InsertAfterNode(33,44);
    d1.DeleteBeforeNode(33); 
    cout << "\n";
    return 0;
}