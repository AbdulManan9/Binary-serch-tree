#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node*left;
		Node*right;
		Node(int d)
		{
			this->data=d;
			this->left=NULL;
			this->right=NULL;
		}
};
Node* insertToBST(Node*&root,int data)
{
	while(data!=-1)
	{
		Node*root=NULL;
		cout<<"Enter data"<<endl;
		cin>>data;
		if(root=NULL)
	{
		root=new Node(data);
		return root;
	}
	if(data>root->data)
	{
		root->right=insertToBST(root->right,data);
	}
	else
	{
		root->left=insertToBST(root->left,data);
		
	}
	return root;
}

	}
	
int main()
{
	Node*root=NULL;
	insertToBST(root,NULL);
}
