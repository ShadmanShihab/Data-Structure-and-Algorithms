//Trie
//Prefix tree / Redix tree
//time complexity: O(length)
//implemented using linked list

#include <bits/stdc++.h>
using namespace std;

struct node{
    bool wordend;
    node* next[27];

    node()
    {
        wordend = false;
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }
};

node* root;

void Insert(char *str)
{
    int len = strlen(str);
    node* curr = root;

    for(int i=0; i<len; i++)
    {
        int id = str[i] - 'a';

        if(curr->next[id] == NULL)
            curr->next[id] = new node();

        curr = curr->next[id];
    }
    curr->wordend = true;
}

bool Search(char* str)
{
    int len = strlen(str);
    node* curr = root;

    for(int i=0; i<len; i++)
    {
        int id = str[i] - 'a';

        if(curr->next[id] == NULL)
            return false;

        curr = curr->next[id];
    }

    return curr->wordend;
}

void del(node* curr)
{
    for(int i=0; i<26; i++)
        if(curr->next[i])
            del(curr->next[i]);
    delete(curr);
}

int main()
{
    root = new node();

    puts("Enter number of nodes: ");
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        char str[50];
        scanf("%s", str);
        Insert(str);
    }


    int query; cin>>query;

    for(int i=0; i<query; i++)
    {
        char str[50];
        scanf("%s", str);
        if(Search(str))
            cout<<"Word found\n";
        else
            cout<<"Word not found\n";
    }

    del(root);
    return 0;
}
