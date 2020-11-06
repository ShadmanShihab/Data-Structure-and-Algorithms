#include <bits/stdc++.h>
using namespace std;

#define Max 1005


class Queue
{
private:
    int ara[Max], front, rear;
public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if(front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(front == -1 && rear == Max-1)
            return true;
        else
            return false;
    }

    void enQueue(int value)
    {
        if(isFull())
        {
            cout<<"Queue is full\n";
        }
        else
        {
            if(front == -1) front = 0;
            rear++;
            ara[rear] = value;
            cout<<ara[rear]<<" is pushed to queue\n";
        }
    }


    int deQueue()
    {
        int value;
        if(isEmpty())
        {
            cout << "Queue is empty!!" << endl;
            return(-1);
        }
        else
        {
            value = ara[front];
            if(front >= rear)
            {      //only one element in queue
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            cout << endl << "Deleted => " << value << " from myqueue\n";
            return(value);
        }
    }


    void display()
    {
        cout<<"Queue: \n";
        for(int i=front; i<=rear; i++)
            cout<<ara[i]<<" ";
        cout<<endl;
    }
};



int main()
{
    Queue q;
    cout<<q.isEmpty()<<endl;

    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    q.display();

    q.enQueue(30);
    q.enQueue(40);
    q.deQueue();
    q.display();

    return 0;
}
