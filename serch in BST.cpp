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
bool serchBST(Node *& root,int element)
{
	if(root==NULL)
	{
		cout<<"False";
	}
	if(root->data > element)
	{
		return serchBST(root->left,element);
	}
	else if(root->data == element)
	{
		cout<<"true" ;
	}
	
	else
	{
		return serchBST(root->right,element);
	}
}
/*bool searchBST(Node* &root,int d)
	{

		while(root != NULL)
		{
			
			if(d == root->data)
			{
				return true;
			}
			else if(d > root->data)
			{
				root = root->right;
			}
			else if(d < root->data)
			{
				root = root->left;
			}
		}
		return false;
	}*/
	int chuckMinValue(Node *& root)
	{
		Node*current=root;
		while(current->left!=NULL)
		{
			current=current->left;
		}
		cout<< current->data<<endl;
	}
	int chuckMaxValue(Node*& root)
	{
		Node*current=root;
		while(current->right!=NULL)
		{
			current=current->right;
		}
		cout<<current->data<<endl;
	}
	
void secondLargestUtil(Node *root, int &c)
{
    if (root == NULL || c >= 2)
        return;

    secondLargestUtil(root->right, c);
    c++;
    if (c == 2)
    {
        cout<< root->data << endl;
        return;
    }
    secondLargestUtil(root->left, c);
}
void secondLargest(Node *root)
{
    int c = 0;
    secondLargestUtil(root, c);
}
int main()
{
	Node*root=NULL;
	valueBST(root);
	cout<<"Inorder triversal"<<endl;
	Inorder(root);
	cout<<"Enter which element you can find in BST"<<endl;
	int x;
	cin>>x;
	serchBST(root,x);
	cout<<"Minimum value in binary serch ree "<<endl;
	chuckMinValue(root);
	cout<<"Maximum value in Binary serch tree"<<endl;
	chuckMaxValue(root);
	cout<<"Two chuck second max value"<<endl;
	secondLargest(root);
}
