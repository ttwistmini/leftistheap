#include <iostream>
using namespace std;

typedef struct Node
{
   int data;
   Node* left;
   Node* right;

   Node(int key)
   {
      data = key;
      left = right = NULL;
   }
}
node;

int dist(node*);
void insert(node*&,node*&);
void inorder(node*);
void preorder(node*);
void postorder(node*);
int height(node*);
void printlevel(node*,int);
void levelorder(node*);
int deleteMin(node*&);

int dist(node* root)
{
   if(root == NULL)
      return -1;
   else
      return min(dist(root->left),dist(root->right))+1;
}

void check_leftist(node*& root)
{
   if(dist(root) != dist(root->right)+1)
   {
      swap(root->left,root->right);
   }
}

void insert(node*& root,node*& key)
{
   if(root == NULL)
   {
      root = key;
      return;
   }
   if(key == NULL)
      return;
   if(root->data <= key->data)
   {
      if(root->left == NULL)
         insert(root->left,key);
      else if(root->right == NULL)
         insert(root->right,key);
      else
      {
         insert(root->right,key);
      }
   }
   else if(root->data > key->data)
   {
      swap(root,key);
      insert(root,key);
   }
   check_leftist(root);
}

void inorder(node* root)
{
   if(root != NULL)
   {
      inorder(root->left);
      cout<< root->data <<endl;
      inorder(root->right);
   }
}

void preorder(node* root)
{
   if(root != NULL)
   {
      cout<< root->data <<endl;
      preorder(root->left);
      preorder(root->right);
   }
}

void postorder(node* root)
{
   if(root != NULL)
   {
      postorder(root->left);
      postorder(root->right);
      cout<< root->data <<endl;
   }
}

int height(node* root)
{
   if(root == NULL)
      return -1;
   else
      return max(height(root->left),height(root->right))+1;
}

void printlevel(node* root,int level)
{
   if(root == NULL)
      return;
   if(level == 0)
   {
      cout<< root->data <<endl;
   }
   else
   {
      printlevel(root->left,level-1);
      printlevel(root->right,level-1);
   }
}

void levelorder(node* root)
{
   for(int i = 0; i <= height(root); i++)
   {
      printlevel(root,i);
   }
}

int deleteMin(node*& root)
{
   node* temp = root;
   int min = root->data;
   insert(root->left,root->right);
   root = root->left;
   delete temp;
   return min;
}
