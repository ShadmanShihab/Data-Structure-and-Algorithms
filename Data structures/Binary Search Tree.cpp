#include <bits/stdc++.h>
using namespace std;

struct BstNode{
    int data;
    BstNode* left = NULL;
    BstNode* right = NULL;
};

BstNode* getNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root,  int data)
{
    if(root == NULL)
        root = getNewNode(data);

    else if(data <= root->data)
        root->left = Insert(root->left, data);

    else
        root->right = Insert(root->right, data);

    return root;
}

bool Search(BstNode* root, int data)
{
    if(root == NULL)
        return false;
    else if(root->data == data)
        return true;
    else if(data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

int Min_Element_in_BST(BstNode* root)
{
    if(root == NULL)
    {
        cout<<"BST is empty\n";
        return -1;
    }
    BstNode* current = root;
    while(current->left != NULL)
          current = current->left;

    return current->data;
}

int Max_Element_in_BST(BstNode* root)
{
    if(root == NULL)
    {
        cout<<"BST is empty\n";
        return -1;
    }
    BstNode* current = root;
    while(current->right != NULL)
          current = current->right;

    return current->data;
}

void inorder(BstNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

BstNode* Findmin(BstNode *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

BstNode* Delete(BstNode* root, int data)
{
    if(root == NULL)
        return root;

    else if(data < root->data)
        root->left = Delete(root->left, data);

    else if(data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        //Case 1: No Child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root = NULL;
        }
        //case 2: one child
        else if(root->left == NULL)
        {
            BstNode* temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if(root->right == NULL)
        {
            BstNode* temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        else
        {
            BstNode* temp = Findmin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    //int n; cin>>n;

    if(Search(root, 15)) cout<<"Item found"<<endl;
    else cout<<"not found\n";


    //cout<<Min_Element_in_BST(root)<<endl;

   // cout<<Max_Element_in_BST(root)<<endl;


    //BST in order traversal
    cout<<"Inorder traversal: \n\n";
    inorder(root);

    root = Delete(root, 15);
    cout<<"\n\nAfter deletion: \n";
    inorder(root);
    return 0;
}

