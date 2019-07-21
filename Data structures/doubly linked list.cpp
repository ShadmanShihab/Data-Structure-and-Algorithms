#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pfi(n) printf("%d\n", n)
#define sci(n) scanf("%d", &n)
#define rep(i, n) for(int i=0; i<n; i++)
#define repi(i, n) for(int i=1; i<=n; i++)
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define Max 100005;
long long limit = 4294967296;

template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}

struct node{
    int data;
    struct node* next;
    struct node* prev;

};

struct node* head, tail;

void insertAtHead(int x)
{
    struct node* tail = new node();
    struct node* newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;

    head = newNode;

    struct node* temp = head;
    while(temp != NULL)
    {
        tail = temp;
        temp = temp->next;
    }

}

void print()
{
    struct node* temp = head;
    cout<<"Traversing in forward direction: \n";

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reversePrint()
{
    struct node* temp = head;
    if(temp == NULL)
        return;

    while(temp->next != NULL)   //going to the last node
        temp = temp->next;

    cout<<"Traversing in reverse order: \n";

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}

void deleteNode(int pos)
{
    if(head == NULL)
    {
        cout<<" Can't delete. List is empty.\n";
        return;
    }
    struct node *temp = head;

    struct node *prevNode = new node();
    struct node *nextNode = new node();

    for(int i=1; i<=pos; i++)
    {
        if(i == pos)
            cout<<temp->data<<" is deleted\n";

        prevNode = temp->prev;
        nextNode = temp->next;
        temp = temp->next;
    }

    prevNode->next = nextNode;
    nextNode->prev = prevNode;


}

void searchNode(int value)
{
    struct node* temp = head;
    int c = 0;
    while(temp != NULL)
    {
        c++;
        if(temp->data == value)
        {
            cout<<value<<" found at position "<<c<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<value<<" not found in the linked list"<<endl;
}

void Sort()
{
    struct node* index = new node();
    struct node* current = new node();
    struct node* temp = new node();

    temp = head;
    //dbg(temp->data);
    while(temp != NULL)
    {
        current = temp;
        index = current;

        while(index != NULL)
        {
            if(current->data > index->data)
                swap(current->data, index->data);
            index = index->next;
        }
        temp = temp->next;
    }
    cout<<"\n\nSorted linked list : \n";
    print();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    insertAtHead(5);
    insertAtHead(15);
    insertAtHead(50);
    insertAtHead(25);
    insertAtHead(6);

    print();
    reversePrint();

    deleteNode(3); // enter position


    print();

    searchNode(25);
    searchNode(225);

    Sort();
    //print();
    return 0;
}
