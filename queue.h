#ifndef queue_h
#define queue_h
#include "node.h"


class Queue{
private:
    struct Node {
     int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
    };

    Node* headPtr;
    Node* tailPtr;
    int size;

    typedef Node* NodePtr;

public:

    Queue() : headPtr(nullptr),tailPtr(nullptr), size(0) {};
    ~Queue() 
    {
        while (!empty())
        {
            dequeue();
        }
    }

    bool empty()
    {
        return size == 0;
    }

    int front();
    void enqueue(int x);
    int dequeue();
    void preview()
    {
        Node* cur = headPtr;
        if (cur != nullptr)
        {
            cout << cur->data;
            if (cur -> next != nullptr)
            {
             cur = cur -> next -> next;
            }
            else
            {
                cur = nullptr;
            }
        }
        cout << endl;
    }
    


};

int Queue::front()//get the frist thing in the list
{
    if (empty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return headPtr -> data;
}


void Queue::enqueue(int x)
{
    NodePtr new_node = new Node (x);
    if(new_node)
    {
        /*Add head and tail*/
        //cinnect and change tail
        if (size > 0) //if(tailPtr != NULL) | if(headPtr) either one works
            tailPtr->next = new_node;//can't do this when it's NULL
        else headPtr = new_node;


        //change head when the queue is empty
        tailPtr=new_node;

        //add size
        ++size;
    }
}

int Queue::dequeue()
{
    if (size > 0) //if (headPtr != NULL)
    {
        NodePtr t = headPtr;
        int value = t -> data;

        headPtr = headPtr -> next;
        delete t;
        //add head and tail

        size--;
        if (size == 0) 
    tailPtr == nullptr;
    
    return value;
    } 
    cout << "Empty queue";
    return -1;
}

#endif