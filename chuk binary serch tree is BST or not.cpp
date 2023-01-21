#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* left;
		Node* right;
	Node(int d)
	{
		this->data=d;
		this->left=NULL;
		this->right=NULL;
		}	
};
Node *insertToBST(Node* &root,int d)
{
	if(root==NULL)
	{
		root=new Node(d);
		return root;
	}
	if(d > root->data)
	{
		root->right=insertToBST(root->right,d);
	}
	else
	{
		root->left=insertToBST(root->left,d);
	}
	return root;
}
void valueBST(Node*& root)
{
	int data;
	cout<<"Enter data for binary serch tree"<<endl;
	cin>>data;
	while(data!=-1)
	{
		insertToBST(root,data);
		cin>>data;
	}
}
Node* Inorder(Node*& root)
{
	if(root==NULL)
	{
		return NULL;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
	return root;
}
int maxValue(Node* root)
{
    if (root == NULL) {
        return 0;
    }
 
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);
 
    int value = 0;
    if (leftMax > rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }
 
    if (value < root->data) {
        value = root->data;
    }
 
    return value;
}
int minValue(Node *root)
{
    if (root == NULL) {
        return 1000000000;
    }
 
    int leftMax = minValue(root->left);
    int rightMax = minValue(root->right);
 
    int value = 0;
    if (leftMax < rightMax) {
        value = leftMax;
    }
    else {
        value = rightMax;
    }
 
    if (value > root->data) {
        value = root->data;
    }
 
    return value;
}
int isBST(Node* root)
{
    if (root == NULL)
        return 1;
    if (root->left != NULL
        && maxValue(root->left) > root->data)
        return  0;
 if (root->right != NULL
        && minValue(root->right) < root->data)
        return 1;
    if (!isBST(root->left) || !isBST(root->right))
        return 0;
    return 1;
}
  
int main()
{
	Node*root=NULL;
	valueBST(root);
	cout<<"Inorder Triversal"<<endl;
	Inorder(root);
	cout<<"Chuck it is BST or not"<<endl;
	
	if(isBST(root))
	{
		cout<<"Is BST"<<endl;
	}
	else
	{
		cout<<"Not a BST"<<endl;
	}
}
