// method 1:- efficient for check is BST or not.

#include <bits/stdc++.h>
using namespace std;
// property :- A binary tree is BST iff inorder travarsal of it is in increasing order.
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
int prevv=INT_MIN;
bool isBST(Node *root)
{
    if(root==NULL)
    {
        return true;
    }
    if(isBST(root->left)==false)
    {
        return false;
    }
    if(root->data <=prevv)
    {
        return false;
    }
    prevv=root->data;
    return isBST(root->right);

}
 int main()
{
   	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(6);  
    root->left->right = new Node(3); 
    if(isBST(root))
    {
        cout<<"tree is BST"<<endl;
    }
    else
    cout<<"not BST"<<endl;
    return 0;
}




// method 2:- 
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
/*  Algorithm.

    (1). PASS A RANGE FOR EVERY NODE.
    (2). for root,range is -infite to +infite
    (3). for left child of a node, in range we change upper bound as the node's value.
    (4). for right child of a node , in a range we change lower bound as the node's value.
    
*/
bool isBST(Node *root,int min,int max)
{
if(root==NULL)
{
    return true;
}
return (root->data>min && root->data <max && isBST(root->left,min,root->data)&& isBST(root->right,root->data,max));
}
int main()
{
   	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(6);  
    root->left->right = new Node(3);
    if(isBST(root,INT_MIN,INT_MAX))
    {
        cout<<"tree is BST"<<endl;
    }
    else
    cout<<"not BST"<<endl;
    return 0;
}
 


//method 3:- inefficient solution 
// becz time complexity is O(n^2) 
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
int max_value(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    int res = root->data;
    int lres = max_value(root->left);
    int rres = max_value(root->right);
    res = max(res, max(lres, rres));
    return res;
}
int min_value(Node *root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    int res=root->data;
    int lres=min_value(root->left);
    int rres=min_value(root->right);
    res=min(res,min(lres,rres));
    return res;
}
bool isBST(Node *root)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->left!= NULL && max_value(root->left)>root->data)
    {
        return false;
    }
    if(root->right!= NULL && min_value(root->right)<root->data)
    {
        return false;
    }    
    return true;
}
int main()
{
   	Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(6);  
    root->left->right = new Node(3); 
    // cout << max_value(root) << endl;
    if(isBST(root))
    {
        cout<<"tree is BST"<<endl;
    }
    else
    cout<<"not BST"<<endl;
    return 0;
}

