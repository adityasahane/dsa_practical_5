/*

Conversion of Binary Tree to Threaded Binary Tree
✓ Do the reverse inorder traversal, means visit right child first.
✓ In recursive call, pass additional parameter, the node visited previously.
✓ whenever you will find a node whose right pointer is NULL and previous visited node is not
    NULL then make the right of node points to previous visited node and mark the boolean right
    Threaded as true.
✓ Whenever making a recursive call to right subtree, do not change the previous visited not and
    when making a recursive call to left subtree then pass the actual previous visited node.

*/



#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    bool thread = false;

    Node(int val)
    {
        data = val;
    }
};

void insert_in_tree(Node *root, int val)
{
    Node *new_node = new Node(val);

    if(root == nullptr)
        root = new_node;

    if(val < root->data)
    {
        if(root->left == nullptr)
            root->left = new_node;
        else
            insert_in_tree(root->left, val);
    }
    else
    {
        if(root->right == nullptr)
            root->right = new_node;
        else
            insert_in_tree(root->right, val);
    }

}

void convert_to_tbt(Node *root, Node *prev)
{
    if(root == nullptr)
        return;
    
    convert_to_tbt(root->left, root);
    if(root->right == nullptr && prev != nullptr)
    {
        root->thread = true;
    }
    convert_to_tbt(root->right, prev);
    
}

void check_tbt(Node *root)
{
    if(root == nullptr)
        return;

    check_tbt(root->left);

    if(root->thread)
        cout<<root->data<<" ";

    check_tbt(root->right);
}


int main()
{
    Node *root = new Node(6);

    bool toggle = 1;

    while(toggle)
    {
        int val;
        cout<<"Enter Number: ";
        cin>>val;

        insert_in_tree(root, val);

        cout<<"Do You Want to Continue? 1/0: ";
        cin>>toggle;
    }

    convert_to_tbt(root, nullptr);
    check_tbt(root);

    return 0;
}