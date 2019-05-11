//linked list
//O(n)
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *next;
};

node *root = NULL;

void append(int roll)
{
    if(root == NULL)
    {
        root = new node();
        root->roll = roll;
        root->next = NULL;
    }
    else
    {
        node *current_node = root;

        while(current_node->next != NULL)
        {
            current_node = current_node->next;
        }
        node *newnode = new node();
        newnode->roll = roll;
        newnode->next = NULL;

        current_node->next = newnode;
    }
}

void print()
{
    node *current_node = root;
    while(current_node != NULL)
    {
        printf("%d  ", current_node->roll);
        current_node = current_node->next;
    }
}

void delete_node(int roll)
{
    node *current_node = root;
    node *previous_node = root;

    while(current_node->roll != roll)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if(current_node == root)
    {
        node *temp = root;
        root = root->next;
        delete(temp);
    }
    else
    {
        previous_node->next = current_node->next;
        delete(current_node);
    }
}

void insert_node(int roll1, int roll2)
{
    node *current_node = root;
    node *next_node = new node();
    node *insertNode = new node();
    node *previous_node = new node();

    insertNode->roll = roll2;
    insertNode->next = NULL;

    while(current_node->roll != roll1)
    {
        current_node = current_node->next;
    }
    next_node = current_node->next;

    if(current_node == root)
    {
        node *temp = root;
        insertNode->next = temp->next;
        root->next = insertNode;
    }
    else
    {
        insertNode->next = next_node;
        current_node->next = insertNode;
    }
}

int main()
{
    int n;
    cout<<"Enter the no of elements: \n";
    cin>>n;

    for(int i=1; i<=n; i++)
        append(i);

    while(1)
    {
        cout<<"1. print -> "<<endl;
        cout<<"2. insert -> "<<endl;
        cout<<"3. delete -> "<<endl;
        cout<<"0. break"<<endl;

        cin>>n; if(n == 0) break;

        switch(n)
        {
        case 1:
            cout<<"LInked list: "<<endl;
            print();
            cout<<endl<<endl;;
            break;

        case 2:
            int pos, item;
            cout<<"Enter the position and data to insert: "<<endl;
            cin>>pos>>item;
            insert_node(pos, item);
            break;

        case 3:
            int del;
            cout<<"Enter the value to delete: ";
            cin>>del;
            delete_node(del);
            break;
        }
    }
    return 0;
}
