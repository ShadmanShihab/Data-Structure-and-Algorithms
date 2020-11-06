#include <bits/stdc++.h>
using namespace std;

#define Max 1005

class Stack{

    int top;

public:
    int ara[Max]; //size of stack

    Stack() //constructor
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if(top >= Max-1)
    {
        cout<<"Stack Overflow\n";
        return false;
    }
    else
    {
        ara[++top] = x;
        cout<<x<<" pushed into the stack\n";
        return true;
    }
}

int Stack::pop()
{
    if(top < 0)
    {
        cout<<"Stack Underflow\n";
        return 0;
    }
    else
    {
        int x = ara[top];
        top--;
        return x;
    }
}

int Stack::peek()
{
    if(top < 0)
    {
        cout<<"Stack is empty";
        return 0;
    }
    else{
        return ara[top];
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while(!s.isEmpty())
    {
        cout<<s.pop()<<endl;
    }
}
