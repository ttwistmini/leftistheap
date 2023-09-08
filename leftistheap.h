#pragma once
#include <iostream>
#include <vector>
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

void levelordertraversal(node* head)
{
        if(head==NULL)
                return ;
        std::vector<node*> parentnodes,childnodes;
        node* ptr=head;
        childnodes.push_back(head);
        while(!childnodes.empty())
        {
        parentnodes.clear();
        parentnodes=childnodes;
        childnodes.clear();
        for(node* temp : parentnodes)
        {
                if(temp->left!=NULL)
                        childnodes.push_back(temp->left);
                if(temp->right!=NULL)
                        childnodes.push_back(temp->right);
        }
        for(node* temp : parentnodes)//printing parents
        {
                std::cout<<temp->key<<" ";
        }
        std::cout<<std::endl;
        }
}

int dist(node* root)
{
	if(root==NULL)
		return -1;
	return dist(root->right)+1;
}

node* merge(node* &A,node* &B)
{
	if(A==NULL)
		return B;
	if(B==NULL)
		return A;
	if(A->key > B->key)
		std::swap(A,B);
	A->right=merge(A->right,B);
	if(dist(A->right) > dist(A->left))
		swap(A->left,A->right);
	return A;
}

node* insert(node* &root,int key)
{
	root=merge(root,new node(key));
	return root;
}

node* deletenode(node*& root)
{
	node* del=root;
	root=merge(root->left,root->right);
	return root;
}
