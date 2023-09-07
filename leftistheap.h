#pragma once
#include <iostream>
typedef struct node
{
	node* left=NULL;
	int key=0;
	node* right=NULL;

	node(int key)
	{
		this->key=key;
		left=NULL;
		right=NULL;
	}
}node;

int dist(node* root)
{
	if(root==NULL)
		return -1;
	return dist(root->right)+1;
}

node* insert(node* &root,int key)
{
	return root=insertnode(root,new node(key));
}

node* insertnode(node* A,node* B)
{
	if(A==NULL)
		A=B;

	else if(A->key < B->key)
	{
		if(A->left == NULL)
			A->left=B;
		else
			A->right=insertnode(A->right,B);
	}

	else if(A->key > B->key)
	{
		std::swap(A,B);
		A=insertnode(A,B);
	}

	if( dist(A->left) < dist(A->right))
		std::swap(A->left,A->right);

	return A;
}
