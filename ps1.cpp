#include "leftistheap.h"
#include <vector>

void inorderTraversal(node*,node*,int&,int&);
void findMaxAnd(node*,node*,int&,int&);

int main()
{
   node* root = NULL;
   int n,t;
   cout<<"Enter the number of elements: ";
   cin>>n;
   cout<<"Enter the elements of the array"<<endl;
   vector<int> arr;
   for(int i = 0; i < n; i++)
   {
      cin>>t;
      arr.push_back(t);
   }
   node* temp;
   for(int i : arr)
   {
      temp = new node(i);
      insert(root,temp);
   }
   int max1 = 0, max2 = 0;
   while(root != NULL)
   {
      inorderTraversal(root,root,max1,max2);
      deleteMin(root);
   }
   cout<<"The bitwise AND value of "<<max1<<" and "<<max2<<" is the largest"<<endl;
   cout<<max1<<" & "<<max2<<" = "<<(max1 & max2)<<endl;
}

void inorderTraversal(node* root,node* ptr,int& max1,int& max2)
{
   if(root != NULL)
   {
      inorderTraversal(root->left,ptr,max1,max2);
      if(root != ptr)
         findMaxAnd(root,ptr,max1,max2);
      inorderTraversal(root->right,ptr,max1,max2);
   }
}

void findMaxAnd(node* root,node* ptr,int& max1,int& max2)
{
   if((root->data & ptr->data) > (max1 & max2))
   {
      max1 = root->data;
      max2 = ptr->data;
   }
}
